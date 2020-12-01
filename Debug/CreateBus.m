% vec = ['x_gh', 'x_g', 'x_h', 'MCC' , 'CBI3_stimON' , 'CBI3_stimOFF' , ...
%     'CBI3_refractory' , 'B40B30_offTime' , 'unbroken', 'use_hypothesized_connections', ...
%     'CBI2', 'stim_CBI2' , 'B64' , 'sens_mechanical_lips' , 'sens_chemical_lips' , ...
%     'sens_mechanical_grasper' , 'B4B5' , 'refractory_CBI3' , 'CBI3' , 'CBI4', ...
%     'B64_proprioception' , 'thresh_B64_swallow_protract' , 'thresh_B64_bite_protract' , ...
%     'thresh_B64_reject_protract' , 'B31B32' , 'thresh_B4B5_protract', 'stim_B4B5', ...
%     'B20', '']

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
    "grasper_friction_state", "jaw_friction_state", "seaweed_strength", "fixation_type", "force_on_object",...
    "sens_chemical_lips", "sens_mechanical_lips", "sens_mechanical_grasper", "use_hypothesized_connections", "stim_B4B5", "stim_CBI2",...
    "CBI3_stimON","CBI3_stimOFF","CBI3_refractory","B40B30_offTime","unbroken", ...
    "switchBehavior","behavior_1","behavior_2","t_switch"]

clear elems obj


for n = 1:length(vec)
    elems(n) = Simulink.BusElement;
    elems(n).Name = vec(n);
%     if vec(n) =="behavior" || vec(n) =="behavior_1" ...
%             || vec(n) =="behavior_2"
%             
%         elems(n).DataType="stringtype(6)"
%         %elems(n).Dimensions = 20;
%     end

end



AplysiaBus = Simulink.Bus;
AplysiaBus.Elements = elems;

%--------------
%initialization
%--------------

obj.MCC = 1;
obj.CBI2 = 1;
obj.CBI3 = 0;
obj.CBI4 = 0;
obj.B64 = 0;
obj.B4B5 = 0;
obj.B40B30 = 0;
obj.B31B32 = 1;
obj.B6B9B3 = 0;
obj.B8 = 0;
obj.B7 = 0;
obj.B38 = 1;
obj.B20 = 0;

obj.P_I4 = 0;
obj.A_I4 = 0.05;
obj.P_I3_anterior = 0;
obj.A_I3_anterior = 0.05;
obj.T_I3 = 0.05;
obj.A_I3 = 0.05;
obj.T_I2 = 0.05;
obj.A_I2 = 0.05;
obj.T_hinge = 0;
obj.A_hinge = 0.05;


obj.x_h = 0;
obj.x_g = 0.1;
obj.grasper_friction_state = 0;
obj.jaw_friction_state = 0;
obj.force_on_object = 0;

%switches
obj.use_hypothesized_connections = 0; %1 = yes, 0 = no

%initialize electrodes to zero
obj.stim_B4B5 = 0;
obj.stim_CBI2 = 0;




%Timing variables
obj.TimeStep = 0.05;            %time step in seconds
obj.StartingTime = 0;           %simulation start time (in seconds)
obj.EndTime = 40;               %simulation end time (in seconds)

%Maximum muscle forces
obj.max_I4 = 1.75;              %Maximum pressure grasper can exert on food
obj.max_I3ant = 0.6;            %Maximum I3 anterior force
obj.max_I3 = 1;                 %Maximum I3 force
obj.max_I2 = 1.5;               %Maximum I2 force
obj.max_hinge = 0.2;            %Maximum hinge force

%Muscle time constants
obj.tau_I4 = 1.0/sqrt(2);              %time constant (in seconds) for I4 activation
obj.tau_I3anterior = 2.0/sqrt(2);      %time constant (in seconds) for I3anterior activation
obj.tau_I2_ingestion = 0.5*1/sqrt(2);  %time constant (in seconds) for I2 activation during ingestion
obj.tau_I2_egestion = 1.4*1/sqrt(2);   %time constant (in seconds) for I2 activation during egestion
obj.tau_I3 = 1.0/sqrt(2);              %time constant (in seconds) for I3 activation
obj.tau_hinge  = 1.0/sqrt(2);          %time constant (in seconds) for hinge activation

%body time constants
obj.c_g = 1.0;                  %time constant (in seconds) for grapser motion
obj.c_h = 1.0;                  %time constant (in seconds) for body motion

%Spring constants
obj.K_sp_h = 2.0;       %spring constant representing neck and body between head and ground
obj.K_sp_g = 0.1;       %spring constant representing attachment between buccal mass and head

%Reference points for springs
obj.x_h_ref = 0.0;      %head spring reference position
obj.x_gh_ref = 0.4;     %grasper spring reference position

%Friction coefficients
obj.mu_s_g = 0.4;               %mu_s coefficient of static friction at grasper
obj.mu_k_g = 0.3;               %mu_k coefficient of kinetic friction at grasper
obj.mu_s_h = 0.3;               %mu_s coefficient of static friction at jaws
obj.mu_k_h = 0.3;               %mu_k coefficient of kinetic friction at jaws

%Sensory feedback thresholds (theshold_neuron name_behavior_type)
obj.thresh_B64_bite_protract = 0.89;
obj.thresh_B64_swallow_protract = 0.4;
obj.thresh_B64_reject_protract = 0.5;

obj.thresh_B4B5_protract = 0.7;

obj.thresh_B31_bite_off = 0.55;
obj.thresh_B31_swallow_off = 0.4;
obj.thresh_B31_reject_off = 0.6;
obj.thresh_B31_bite_on = 0.9;
obj.thresh_B31_swallow_on = 0.75;
obj.thresh_B31_reject_on = 0.89;

obj.thresh_B7_bite_protract = 0.9;
obj.thresh_B7_reject_protract = 0.7;

obj.thresh_B6B9B3_bite_pressure = 0.2;
obj.thresh_B6B9B3_swallow_pressure = 0.25;
obj.thresh_B6B9B3_reject_pressure = 0.75;

obj.thresh_B38_retract = 0.4;

%neural timing variables
obj.refractory_CBI3 = 5000;                 %refractory period (in milliseconds) of CBI3 post strong B4B5 excitation
obj.postActivityExcitation_B40B30 = 3000;   %time (in milliseconds) post B40B30 activity that slow excitation lasts

%environment variables
obj.seaweed_strength = 10;
obj.fixation_type = 1;          %default initialization is seaweed fixed to the force transducer (use for swallowing)

%% Initialize internal tracking variables
obj.CBI3_stimON = 0;
obj.CBI3_stimOFF = 0;
obj.CBI3_refractory = 0;
obj.B40B30_offTime = 0;
obj.unbroken = 1; %tracking variable to keep track of seaweed being broken off during feeding


%%behavior variables
obj.switchBehavior=0; %0 = don't switch behavior, 1 = switch behavior
obj.behavior_1=2%'bite'; %bite =1 , swallow = 2, reject =3 
obj.behavior_2=2%'swallow';%bite =1 , swallow = 2, reject =3 
obj.t_switch = 0; %time to switch
%, ...
%    "switchBehavior","behavior_1","behavior_2","t_switch"
%bst.behavior='bite';