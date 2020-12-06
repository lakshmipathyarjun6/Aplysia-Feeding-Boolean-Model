classdef I2_Hill_Type_Muscle_Model
    properties
        I2_struct
    end
    
    methods
        
        function obj = I2_Hill_Type_Muscle_Model()
            
            obj.I2_struct.tau=2.45;
            obj.I2_struct.beta=0.703;
            obj.I2_struct.a0=0.165;
            obj.I2_struct.g_scale=2.0;
            obj.I2_struct.L_st=0; %[m]
            obj.I2_struct.F0=150/1000; %[N] Maximum isometric Force
            obj.I2_struct.L_mto=18.3/1000; %[m]
            obj.I2_struct.L_0 = 0.858*obj.I2_struct.L_mto; %[m]

            obj.I2_struct.v0=0;
            obj.I2_struct.L_m_0=obj.I2_struct.L_mto; %contractile element initial length
            obj.I2_struct.K_t=5*obj.I2_struct.F0/obj.I2_struct.L_0;

            obj.I2_struct.activation_freq=20; %[Hz] frequency of sinusoid input

            obj.I2_struct.v_max=0.007; % [m s^-1] %shortening velocity
            obj.I2_struct.k_I2 = 2.68; %scale factor to span l_mt so that it matches x_gh from l/l_mt0 in range [0,1] 
            
            
            assignin('base','I2_struct',obj.I2_struct)
            
        end
        
    end
   
    
    
end