classdef AplysiaFeedingNew
    properties
        %Maximum muscle forces
        max_I4 = 1.75;              %Maximum pressure grasper can exert on food
        max_I3ant = 0.6;            %Maximum I3 anterior force
        max_I3 = 1;                 %Maximum I3 force
        max_I2 = 1.5;               %Maximum I2 force
        max_hinge = 0.2;            %Maximum hinge force
        
        %Muscle time constants
        tau_I4 = 1.0/sqrt(2);              %time constant (in seconds) for I4 activation
        tau_I3anterior = 2.0/sqrt(2);      %time constant (in seconds) for I3anterior activation
        tau_I3 = 1.0/sqrt(2);              %time constant (in seconds) for I3 activation
        tau_I2_ingestion = 0.5*1/sqrt(2);  %time constant (in seconds) for I2 activation during ingestion
        tau_I2_egestion = 1.4*1/sqrt(2);   %time constant (in seconds) for I2 activation during egestion
        tau_hinge  = 1.0/sqrt(2);          %time constant (in seconds) for hinge activation
        
        %body time constants
        c_g = 1.0;                  %time constant (in seconds) for grapser motion
        c_h = 1.0;                  %time constant (in seconds) for body motion
        
        %Spring constants
        K_sp_h = 2.0;       %spring constant representing neck and body between head and ground
        K_sp_g = 0.1;       %spring constant representing attachment between buccal mass and head
        
        %Reference points for springs
        x_h_ref = 0.0;      %head spring reference position
        x_gh_ref = 0.4;     %grasper spring reference position
        
        x_h_Init = 0;
        x_g_Init = 0.1;
        
        %Friction coefficients
        mu_s_g = 0.4;               %mu_s coefficient of static friction at grasper
        mu_k_g = 0.3;               %mu_k coefficient of kinetic friction at grasper
        mu_s_h = 0.3;               %mu_s coefficient of static friction at jaws
        mu_k_h = 0.3;               %mu_k coefficient of kinetic friction at jaws
        
        %Sensory feedback thresholds (theshold_neuron name_behavior_type)
        thresh_B64_bite_protract = 0.89;
        thresh_B64_swallow_protract = 0.4;
        thresh_B64_reject_protract = 0.5;
        
        thresh_B4B5_protract = 0.7;
        
        thresh_B31_bite_on = 0.9;
        thresh_B31_bite_off = 0.55;
        thresh_B31_swallow_on = 0.75;
        thresh_B31_swallow_off = 0.4;
        thresh_B31_reject_on = 0.89;
        thresh_B31_reject_off = 0.6;
        
        thresh_B6B9B3_bite_pressure = 0.2;
        thresh_B6B9B3_swallow_pressure = 0.25;
        thresh_B6B9B3_reject_pressure = 0.75;
        
        %neural state variables
        MCC_Init = 1;
        CBI2_Init = 1;
        CBI3_Init = 0;
        CBI4_Init = 0;
        B20_Init = 0;
        B40B30_Init = 0;
        B6B9B3_Init = 0;
        B8_Init = 0;
        B64_Init = 0;
        B4B5_Init = 0;
        B31B32_Init = 1;
        B7_Init = 0;
        B38_Init = 1;
        
        P_I4_Init = 0;
        A_I4_Init = 0.05;
        P_I3_anterior_Init = 0;
        A_I3_anterior_Init = 0.05;
        T_I3_Init = 0.05;
        A_I3_Init = 0.05;
        T_I2_Init = 0.05;
        A_I2_Init = 0.05;
        T_hinge_Init = 0;
        A_hinge_Init = 0.05;
        
        %neural timing variables
        refractory_CBI3 = 5;                 %refractory period (in seconds) of CBI3 post strong B4B5 excitation
        postActivityExcitation_B40B30 = 3;   %time (in seconds) post B40B30 activity that slow excitation lasts
        
        %sensory state vectors
        % 10000 = finite large value
        sensory_trigger_time = 10000; 
        
        sens_mechanical_lips_initial = 10000;
        sens_mechanical_lips_final = 10000;
        
        sens_chemical_lips_initial = 10000;
        sens_chemical_lips_final = 10000;
        
        sens_mechanical_grasper_initial = 10000;
        sens_mechanical_grasper_final = 10000;
        
        fixation_type_initial = 10000;
        fixation_type_final = 10000;
        
        %environment variables
        seaweed_strength = 10;
        
        %switches
        use_hypothesized_connections = 0; %1 = yes, 0 = no
        unbroken_Init = 1;
        
        %stimulation electrodes
        stim_B4B5_trigger_time_start = 10000;
        stim_B4B5_trigger_time_end = 10000;
        
        stim_CBI2_trigger_time_start = 10000;
        stim_CBI2_trigger_time_end = 10000;
    end
    
    methods
        %%
        function obj = AplysiaFeedingNew()
            assignin('base','use_hypothesized_connections',obj.use_hypothesized_connections);
            assignin('base','unbroken_Init',obj.unbroken_Init);
            assignin('base','seaweed_strength',obj.seaweed_strength);
            
            assignin('base','max_I4',obj.max_I4);
            assignin('base','max_I3ant',obj.max_I3ant);
            assignin('base','max_I3',obj.max_I3);
            assignin('base','max_I2',obj.max_I2);
            assignin('base','max_hinge',obj.max_hinge);
            
            assignin('base','tau_I4',obj.tau_I4);
            assignin('base','tau_I3anterior',obj.tau_I3anterior);
            assignin('base','tau_I3',obj.tau_I3);
            assignin('base','tau_I2_ingestion',obj.tau_I2_ingestion);
            assignin('base','tau_I2_egestion',obj.tau_I2_egestion);
            assignin('base','tau_hinge',obj.tau_hinge);
            
            assignin('base','c_g',obj.c_g);
            assignin('base','c_h',obj.c_h);
            
            assignin('base','K_sp_h',obj.K_sp_h);
            assignin('base','K_sp_g',obj.K_sp_g);
            
            assignin('base','x_h_ref',obj.x_h_ref);
            assignin('base','x_gh_ref',obj.x_gh_ref);
            
            assignin('base','x_h_Init',obj.x_h_Init);
            assignin('base','x_g_Init',obj.x_g_Init);
            
            assignin('base','mu_s_g',obj.mu_s_g);
            assignin('base','mu_k_g',obj.mu_k_g);
            assignin('base','mu_s_h',obj.mu_s_h);
            assignin('base','mu_k_h',obj.mu_k_h);
            
            assignin('base','thresh_B64_bite_protract',obj.thresh_B64_bite_protract);
            assignin('base','thresh_B64_swallow_protract',obj.thresh_B64_swallow_protract);
            assignin('base','thresh_B64_reject_protract',obj.thresh_B64_reject_protract);
            
            assignin('base','thresh_B4B5_protract',obj.thresh_B4B5_protract);
            
            assignin('base','thresh_B31_bite_on',obj.thresh_B31_bite_on);
            assignin('base','thresh_B31_bite_off',obj.thresh_B31_bite_off);
            assignin('base','thresh_B31_swallow_on',obj.thresh_B31_swallow_on);
            assignin('base','thresh_B31_swallow_off',obj.thresh_B31_swallow_off);
            assignin('base','thresh_B31_reject_on',obj.thresh_B31_reject_on);
            assignin('base','thresh_B31_reject_off',obj.thresh_B31_reject_off);
            
            assignin('base','thresh_B6B9B3_bite_pressure',obj.thresh_B6B9B3_bite_pressure);
            assignin('base','thresh_B6B9B3_swallow_pressure',obj.thresh_B6B9B3_swallow_pressure);
            assignin('base','thresh_B6B9B3_reject_pressure',obj.thresh_B6B9B3_reject_pressure);
            
            assignin('base','refractory_CBI3',obj.refractory_CBI3);
            assignin('base','postActivityExcitation_B40B30',obj.postActivityExcitation_B40B30);
        end
        
        function obj = runSimulation(obj)
            assignin('base','MCC_Init',obj.MCC_Init);
            assignin('base','CBI2_Init',obj.CBI2_Init);
            assignin('base','CBI3_Init',obj.CBI3_Init);
            assignin('base','CBI4_Init',obj.CBI4_Init);
            assignin('base','B20_Init',obj.B20_Init);
            assignin('base','B40B30_Init',obj.B40B30_Init);
            assignin('base','B6B9B3_Init',obj.B6B9B3_Init);
            assignin('base','B8_Init',obj.B8_Init);
            assignin('base','B64_Init',obj.B64_Init);
            assignin('base','B4B5_Init',obj.B4B5_Init);
            assignin('base','B31B32_Init',obj.B31B32_Init);
            assignin('base','B7_Init',obj.B7_Init);
            assignin('base','B38_Init',obj.B38_Init);
            
            assignin('base','P_I4_Init',obj.P_I4_Init);
            assignin('base','A_I4_Init',obj.A_I4_Init);
            assignin('base','P_I3_anterior_Init',obj.P_I3_anterior_Init);
            assignin('base','A_I3_anterior_Init',obj.A_I3_anterior_Init);
            assignin('base','T_I3_Init',obj.T_I3_Init);
            assignin('base','A_I3_Init',obj.A_I3_Init);
            assignin('base','T_I2_Init',obj.T_I2_Init);
            assignin('base','A_I2_Init',obj.A_I2_Init);
            assignin('base','T_hinge_Init',obj.T_hinge_Init);
            assignin('base','A_hinge_Init',obj.A_hinge_Init);
            
            assignin('base','sensory_trigger_time',obj.sensory_trigger_time);
            assignin('base','sens_mechanical_lips_initial',obj.sens_mechanical_lips_initial);
            assignin('base','sens_mechanical_lips_final',obj.sens_mechanical_lips_final);
            assignin('base','sens_chemical_lips_initial',obj.sens_chemical_lips_initial);
            assignin('base','sens_chemical_lips_final',obj.sens_chemical_lips_final);
            assignin('base','sens_mechanical_grasper_initial',obj.sens_mechanical_grasper_initial);
            assignin('base','sens_mechanical_grasper_final',obj.sens_mechanical_grasper_final);
            assignin('base','fixation_type_initial',obj.fixation_type_initial);
            assignin('base','fixation_type_final',obj.fixation_type_final);
            
            assignin('base','stim_B4B5_trigger_time_start',obj.stim_B4B5_trigger_time_start);
            assignin('base','stim_B4B5_trigger_time_end',obj.stim_B4B5_trigger_time_end);
            assignin('base','stim_CBI2_trigger_time_start',obj.stim_CBI2_trigger_time_start);
            assignin('base','stim_CBI2_trigger_time_end',obj.stim_CBI2_trigger_time_end);
            
            sim('AplysiaFeedingSimulation');
        end
        
        function obj = setStimulationTrains(obj,neuron,onTime,duration)
            
            if (strcmp(neuron,'B4B5'))
                obj.stim_B4B5_trigger_time_start = onTime;
                obj.stim_B4B5_trigger_time_end = onTime + duration;   
            end
            
            if (strcmp(neuron,'CBI2'))
                obj.stim_CBI2_trigger_time_start = onTime;
                obj.stim_CBI2_trigger_time_end = onTime + duration;  
            end
            
        end
        
        function obj = setSensoryStates(obj,varargin)
            
            if (nargin == 2)
                behavior = varargin{1};
                if (strcmp(behavior,'bite'))
                    obj.sens_chemical_lips_initial = 1;
                    obj.sens_mechanical_lips_initial = 1;
                    obj.sens_mechanical_grasper_initial = 0;
                    obj.fixation_type_initial = 0;
                elseif (strcmp(behavior,'swallow'))
                    obj.sens_chemical_lips_initial = 1;
                    obj.sens_mechanical_lips_initial = 1;
                    obj.sens_mechanical_grasper_initial = 1;
                    obj.fixation_type_initial = 1;
                elseif (strcmp(behavior,'reject'))
                    obj.sens_chemical_lips_initial = 0;
                    obj.sens_mechanical_lips_initial = 1;
                    obj.sens_mechanical_grasper_initial = 1;
                    obj.fixation_type_initial = 0;
                end
                
            elseif (nargin == 4)
                behavior_1 = varargin{1};
                behavior_2 = varargin{2};
                obj.sensory_trigger_time = varargin{3};
                
                if (strcmp(behavior_1,'bite'))
                    obj.sens_chemical_lips_initial = 1;
                    obj.sens_mechanical_lips_initial = 1;
                    obj.sens_mechanical_grasper_initial = 0;
                    obj.fixation_type_initial = 0;
                elseif (strcmp(behavior_1,'swallow'))
                    obj.sens_chemical_lips_initial = 1;
                    obj.sens_mechanical_lips_initial = 1;
                    obj.sens_mechanical_grasper_initial = 1;
                    obj.fixation_type_initial = 1;
                elseif (strcmp(behavior_1,'reject'))
                    obj.sens_chemical_lips_initial = 0;
                    obj.sens_mechanical_lips_initial = 1;
                    obj.sens_mechanical_grasper_initial = 1;
                    obj.fixation_type_initial = 0;
                end
                
                
                if (strcmp(behavior_2,'bite'))
                    obj.sens_chemical_lips_final = 1;
                    obj.sens_mechanical_lips_final = 1;
                    obj.sens_mechanical_grasper_final = 0;
                    obj.fixation_type_final = 0;
                elseif (strcmp(behavior_2,'swallow'))
                    obj.sens_chemical_lips_final = 1;
                    obj.sens_mechanical_lips_final = 1;
                    obj.sens_mechanical_grasper_final = 1;
                    obj.fixation_type_final = 1;
                elseif (strcmp(behavior_2,'reject'))
                    obj.sens_chemical_lips_final = 0;
                    obj.sens_mechanical_lips_final = 1;
                    obj.sens_mechanical_grasper_final = 1;
                    obj.fixation_type_final = 0;
                end
            end
            
        end
    end
end