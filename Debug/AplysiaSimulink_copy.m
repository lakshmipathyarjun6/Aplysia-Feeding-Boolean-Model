classdef AplysiaSimulink
    properties
        simFileName = "Test"
        init_obj %initial values
        AplysiaBus %Bus definition
        outStruct %output
        stoptime = 10;
        switchBehavior
        behavior_1
        behavior_2
        t_switch
    end
    
    methods
        function init_obj = initializeStruct(obj, switchBehavior, behavior_1, behavior_2, t_switch)           
            %--------------
            %initialization
            %--------------

            init_obj.MCC = 1;
            init_obj.CBI2 = 1;
            init_obj.CBI3 = 0;
            init_obj.CBI4 = 0;
            init_obj.B64 = 0;
            init_obj.B4B5 = 0;
            init_obj.B40B30 = 0;
            init_obj.B31B32 = 1;
            init_obj.B6B9B3 = 0;
            init_obj.B8 = 0;
            init_obj.B7 = 0;
            init_obj.B38 = 1;
            init_obj.B20 = 0;

            init_obj.P_I4 = 0;
            init_obj.A_I4 = 0.05;
            init_obj.P_I3_anterior = 0;
            init_obj.A_I3_anterior = 0.05;
            init_obj.T_I3 = 0.05;
            init_obj.A_I3 = 0.05;
            init_obj.T_I2 = 0.05;
            init_obj.A_I2 = 0.05;
            init_obj.T_hinge = 0;
            init_obj.A_hinge = 0.05;


            init_obj.x_h = 0;
            init_obj.x_g = 0.1;
            init_obj.grasper_friction_state = 0;
            init_obj.jaw_friction_state = 0;
            init_obj.force_on_init_object = 0;

            %switches
            init_obj.use_hypothesized_connections = 0; %1 = yes, 0 = no

            %initialize electrodes to zero
            init_obj.stim_B4B5 = 0;
            init_obj.stim_CBI2 = 0;




            %Timing variables
            init_obj.TimeStep = 0.05;            %time step in seconds
            init_obj.StartingTime = 0;           %simulation start time (in seconds)
            init_obj.EndTime = 40;               %simulation end time (in seconds)

            %Maximum muscle forces
            init_obj.max_I4 = 1.75;              %Maximum pressure grasper can exert on food
            init_obj.max_I3ant = 0.6;            %Maximum I3 anterior force
            init_obj.max_I3 = 1;                 %Maximum I3 force
            init_obj.max_I2 = 1.5;               %Maximum I2 force
            init_obj.max_hinge = 0.2;            %Maximum hinge force

            %Muscle time constants
            init_obj.tau_I4 = 1.0/sqrt(2);              %time constant (in seconds) for I4 activation
            init_obj.tau_I3anterior = 2.0/sqrt(2);      %time constant (in seconds) for I3anterior activation
            init_obj.tau_I2_ingestion = 0.5*1/sqrt(2);  %time constant (in seconds) for I2 activation during ingestion
            init_obj.tau_I2_egestion = 1.4*1/sqrt(2);   %time constant (in seconds) for I2 activation during egestion
            init_obj.tau_I3 = 1.0/sqrt(2);              %time constant (in seconds) for I3 activation
            init_obj.tau_hinge  = 1.0/sqrt(2);          %time constant (in seconds) for hinge activation

            %body time constants
            init_obj.c_g = 1.0;                  %time constant (in seconds) for grapser motion
            init_obj.c_h = 1.0;                  %time constant (in seconds) for body motion

            %Spring constants
            init_obj.K_sp_h = 2.0;       %spring constant representing neck and body between head and ground
            init_obj.K_sp_g = 0.1;       %spring constant representing attachment between buccal mass and head

            %Reference points for springs
            init_obj.x_h_ref = 0.0;      %head spring reference position
            init_obj.x_gh_ref = 0.4;     %grasper spring reference position

            %Friction coefficients
            init_obj.mu_s_g = 0.4;               %mu_s coefficient of static friction at grasper
            init_obj.mu_k_g = 0.3;               %mu_k coefficient of kinetic friction at grasper
            init_obj.mu_s_h = 0.3;               %mu_s coefficient of static friction at jaws
            init_obj.mu_k_h = 0.3;               %mu_k coefficient of kinetic friction at jaws

            %Sensory feedback thresholds (theshold_neuron name_behavior_type)
            init_obj.thresh_B64_bite_protract = 0.89;
            init_obj.thresh_B64_swallow_protract = 0.4;
            init_obj.thresh_B64_reject_protract = 0.5;

            init_obj.thresh_B4B5_protract = 0.7;

            init_obj.thresh_B31_bite_off = 0.55;
            init_obj.thresh_B31_swallow_off = 0.4;
            init_obj.thresh_B31_reject_off = 0.6;
            init_obj.thresh_B31_bite_on = 0.9;
            init_obj.thresh_B31_swallow_on = 0.75;
            init_obj.thresh_B31_reject_on = 0.89;

            init_obj.thresh_B7_bite_protract = 0.9;
            init_obj.thresh_B7_reject_protract = 0.7;

            init_obj.thresh_B6B9B3_bite_pressure = 0.2;
            init_obj.thresh_B6B9B3_swallow_pressure = 0.25;
            init_obj.thresh_B6B9B3_reject_pressure = 0.75;

            init_obj.thresh_B38_retract = 0.4;

            %neural timing variables
            init_obj.refractory_CBI3 = 5000;                 %refractory period (in milliseconds) of CBI3 post strong B4B5 excitation
            init_obj.postActivityExcitation_B40B30 = 3000;   %time (in milliseconds) post B40B30 activity that slow excitation lasts

            %environment variables
            init_obj.seaweed_strength = 10;
            init_obj.fixation_type = 1;          %default initialization is seaweed fixed to the force transducer (use for swallowing)

            %% Initialize internal tracking variables
            init_obj.CBI3_stimON = 0;
            init_obj.CBI3_stimOFF = 0;
            init_obj.CBI3_refractory = 0;
            init_obj.B40B30_offTime = 0;
            init_obj.unbroken = 1; %tracking variable to keep track of seaweed being broken off during feeding


            %%behavior variables
            init_obj.switchBehavior=switchBehavior;  %0 = don't switch behavior, 1 = switch behavior
            init_obj.behavior_1=behavior_1;          %'bite'; %bite =1 , swallow = 2, reject =3 
            init_obj.behavior_2=behavior_2;          %'swallow';%bite =1 , swallow = 2, reject =3 
            init_obj.t_switch = t_switch;            %time to switch
            
            
        end
        
        
        function AplysiaBus = initializeBus(obj)
            
            vec = ["TimeStep", "StartingTime", "EndTime", "max_I4", "max_I3ant", "max_I3",...
            "max_I2", "max_hinge", "tau_I4", "tau_I3anterior", "tau_I2_ingestion", "tau_I2_egestion",...
            "tau_I3", "tau_hinge", "c_g", "c_h", "K_sp_h", "K_sp_g", "x_h_ref", "x_gh_ref",...
            "mu_s_g", "mu_k_g", "mu_s_h", "mu_k_h", "thresh_B64_bite_protract", "thresh_B64_swallow_protract",...
            "thresh_B64_reject_protract", "thresh_B4B5_protract", "thresh_B31_bite_off",...
            "thresh_B31_swallow_off", "thresh_B31_reject_off", "thresh_B31_bite_on",...
            "thresh_B31_swallow_on", "thresh_B31_reject_on", "thresh_B7_bite_protract",...
            "thresh_B7_reject_protract", "thresh_B6B9B3_bite_pressure", "thresh_B6B9B3_swallow_pressure",...
            "thresh_B6B9B3_reject_pressure", "thresh_B38_retract", "MCC", "CBI2", "CBI3", "CBI4", "B64", "B4B5", "B40B30",...
            "B31B32", "B6B9B3", "B8", "B7", "B38", "B20", "refractory_CBI3", "postActivityExcitation_B40B30", "P_I4", "A_I4",...
            "P_I3_anterior", "A_I3_anterior", "T_I3", "A_I3", "T_I2", "A_I2", "T_hinge", "A_hinge", "x_h", "x_g",...
            "grasper_friction_state", "jaw_friction_state", "seaweed_strength", "fixation_type", "force_on_init_object",...
            "sens_chemical_lips", "sens_mechanical_lips", "sens_mechanical_grasper", "use_hypothesized_connections", "stim_B4B5", "stim_CBI2",...
            "CBI3_stimON","CBI3_stimOFF","CBI3_refractory","B40B30_offTime","unbroken", ...
            "switchBehavior","behavior_1","behavior_2","t_switch"]

        clear elems init_obj


        for n = 1:length(vec)
            elems(n) = Simulink.BusElement;
            elems(n).Name = vec(n);
        end



        AplysiaBus = Simulink.Bus;
        AplysiaBus.Elements = elems;
        

            
            
        end
        
        
        
        function outStruct = runSimulation()
            
            out = sim(simFileName,'StopTime',stoptime)
            outStruct = out.outputStruct  
            
        end
        
        
        function obj = AplysiaSimulink( switchBehavior, behavior_1, behavior_2, t_switch)
            obj.init_obj = obj.initializeStruct( switchBehavior, behavior_1, behavior_2, t_switch); 
            obj.AplysiaBus = obj.initializeBus();   
            
        end
        
        
        
        
        
    end
    
end





