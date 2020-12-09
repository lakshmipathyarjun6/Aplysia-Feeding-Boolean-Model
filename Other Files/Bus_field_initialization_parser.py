import re
strp="""obj.MCC = zeros(1, nt);
obj.CBI2 = zeros(1, nt);
obj.CBI3 = zeros(1, nt);
obj.CBI4 = zeros(1, nt);
obj.B64 = zeros(1, nt);
obj.B4B5 = zeros(1, nt);
obj.B40B30 = zeros(1, nt);
obj.B31B32 = zeros(1, nt);
obj.B6B9B3 = zeros(1, nt);
obj.B8 = zeros(1, nt);
obj.B7 = zeros(1, nt);
obj.B38 = zeros(1, nt);
obj.B20 = zeros(1, nt);

% muscle
state
variables
obj.P_I4 = zeros(1, nt);
obj.A_I4 = zeros(1, nt);
obj.P_I3_anterior = zeros(1, nt);
obj.A_I3_anterior = zeros(1, nt);
obj.T_I3 = zeros(1, nt);
obj.A_I3 = zeros(1, nt);
obj.T_I2 = zeros(1, nt);
obj.A_I2 = zeros(1, nt);
obj.T_hinge = zeros(1, nt);
obj.A_hinge = zeros(1, nt);

% body
state
variables
obj.x_h = zeros(1, nt);
obj.x_g = zeros(1, nt);
obj.grasper_friction_state = zeros(1, nt);
obj.jaw_friction_state = zeros(1, nt);

% environment
variables
obj.force_on_object = zeros(1, nt);

"""

re_str= ".*obj.(?P<name>.*).+="

"""for m in re.finditer(re_str,strp):
    m.group(1)
    print("\""+m.group(1)+"\"")
    """


#print(strp)
strp2 = """%Timing variables
        TimeStep = 0.05;            %time step in seconds
        StartingTime = 0;           %simulation start time (in seconds)
        EndTime = 40;               %simulation end time (in seconds)

        %Maximum muscle forces
        max_I4 = 1.75;              %Maximum pressure grasper can exert on food
        max_I3ant = 0.6;            %Maximum I3 anterior force
        max_I3 = 1;                 %Maximum I3 force
        max_I2 = 1.5;               %Maximum I2 force
        max_hinge = 0.2;            %Maximum hinge force

        %Muscle time constants
        tau_I4 = 1.0/sqrt(2);              %time constant (in seconds) for I4 activation
        tau_I3anterior = 2.0/sqrt(2);      %time constant (in seconds) for I3anterior activation
        tau_I2_ingestion = 0.5*1/sqrt(2);  %time constant (in seconds) for I2 activation during ingestion
        tau_I2_egestion = 1.4*1/sqrt(2);   %time constant (in seconds) for I2 activation during egestion
        tau_I3 = 1.0/sqrt(2);              %time constant (in seconds) for I3 activation
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

        thresh_B31_bite_off = 0.55;
        thresh_B31_swallow_off = 0.4;
        thresh_B31_reject_off = 0.6;
        thresh_B31_bite_on = 0.9;
        thresh_B31_swallow_on = 0.75;
        thresh_B31_reject_on = 0.89;

        thresh_B7_bite_protract = 0.9;
        thresh_B7_reject_protract = 0.7;

        thresh_B6B9B3_bite_pressure = 0.2;
        thresh_B6B9B3_swallow_pressure = 0.25;
        thresh_B6B9B3_reject_pressure = 0.75;

        thresh_B38_retract = 0.4;

        %neural state variables
        MCC
        CBI2
        CBI3
        CBI4
        B64
        B4B5
        B40B30
        B31B32
        B6B9B3
        B8
        B7
        B38
        B20

        %neural timing variables
        refractory_CBI3 = 5000;                 %refractory period (in milliseconds) of CBI3 post strong B4B5 excitation
        postActivityExcitation_B40B30 = 3000;   %time (in milliseconds) post B40B30 activity that slow excitation lasts

        %muscle state variables
        P_I4
        A_I4
        P_I3_anterior
        A_I3_anterior
        T_I3
        A_I3
        T_I2
        A_I2
        T_hinge
        A_hinge

        %body state variables
        x_h
        x_g
        grasper_friction_state      %0 = kinetic friction, 1 = static friction
        jaw_friction_state          %0 = kinetic friction, 1 = static friction


        %environment variables
        seaweed_strength = 10;
        fixation_type = 1;          %default initialization is seaweed fixed to the force transducer (use for swallowing)
        force_on_object

        %sensory state vectors
        sens_chemical_lips
        sens_mechanical_lips
        sens_mechanical_grasper

        %switchesm.group
        use_hypothesized_connections = 0; %1 = yes, 0 = no

        %stimulation electrodes
        stim_B4B5 %0 = off, 1 = on
        stim_CBI2 %0 = off, 1 = on"""

re_str2 = "(\s*|(?P<comment>%))(?P<variableName>[a-zA-Z_\d]+).*\n*" #https://regex101.com/r/rfhN8G/1
ve=[]
for m in re.finditer(re_str2,strp2):
    #print(m.groupdict()["comment"])
    if m.groupdict()["comment"] is None:
        print("\""+m.groupdict()["variableName"]+"\"")
        ve.append("\""+m.groupdict()["variableName"]+"\"")
print(", ".join(ve))

