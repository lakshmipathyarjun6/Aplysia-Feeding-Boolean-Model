classdef AplysiaFeedingNew
    properties
        %neural state variables
        MCC_Init = 1;
        CBI2_Init = 1;
        CBI3_Init = 0;
        CBI4_Init = 0;
        B64_Init = 0;
        B4B5_Init = 0;
        
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
        
        %switches
        use_hypothesized_connections = 0; %1 = yes, 0 = no
        
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
        end
        
        function obj = runSimulation(obj)
            assignin('base','MCC_Init',obj.MCC_Init);
            assignin('base','CBI2_Init',obj.CBI2_Init);
            assignin('base','CBI3_Init',obj.CBI3_Init);
            assignin('base','CBI4_Init',obj.CBI4_Init);
            assignin('base','B64_Init',obj.B64_Init);
            assignin('base','B4B5_Init',obj.B4B5_Init);
            
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