close all

tau=2.45;
beta=0.703;
a0=0.165;
g_scale=2.0;
L_st=0; %[m]
F0=150/1000; %[N] Maximum isometric Force
L_mto=18.3/1000; %[m]
L_0 = 0.858*L_mto; %[m]

v0=0;
L_m_0=L_mto; %contractile element initial length
K_t=5*F0/L_0;

activation_freq=20; %[Hz] frequency of sinusoid input

v_max=0.007; % [m s^-1] %shortening velocity

Ramp.rate=0.002; %rate of increase or decrease of muscle length [m/s]
Ramp.start_time=10; %start time for ramp [s]
Ramp.initial_output=L_mto; %initial output before starting ramp should be optimum muscle-tendon length [m]
Ramp.L_max=Ramp.initial_output+0.002; %maximum the muscle-tendon complex can stretch [mm]
Ramp.L_min=Ramp.initial_output-0.002; %minimum the muscle-tendon complex can contract [mm]

rates=[0.5 1 2 -0.5 -1 -2]/1000;
freq =[10 12 14 18];
line_arr=['r-','b-','g-','k-','m-','c-'];

figure()
ax1=subplot(2,1,1)
hold(ax1,'on')
legend();
ax2=subplot(2,1,2)
hold(ax2,'on')
legend()


for n = 1:length(rates)
    Ramp.rate=rates(n);
    init_sim=sim("Hill_type_muscleModel_RampTest",20); %sim with different m
    F_contraction = find(init_sim.F_m.time <=10);
    F_contraction = init_sim.F_m.data(F_contraction(length(F_contraction)));
    
    axes(ax1)
    plot(init_sim.F_m.time,init_sim.F_m.data./F_contraction,line_arr(n),'DisplayName','Rate ='+string(Ramp.rate)+' m/s')
    xlabel('time [s]')
    ylabel('Normalized Force')
    
    axes(ax2)
    plot(init_sim.L_mt.time,(init_sim.L_mt.data - L_mto)*1000,line_arr(n),'DisplayName','Rate ='+string(Ramp.rate)+' m/s')
    xlabel('time [s]')
    ylabel('Change in Muscle Length (mm)')
    
end

figure()
hold on
%frequency vs a(t)
for n = 1:length(freq)
    activation_freq=freq(n);
    init_sim=sim("Hill_type_muscleModel_RampTest",10); %sim with different m

    
    plot(init_sim.a_t.time,init_sim.a_t.data./1.502,line_arr(n),'DisplayName','Rate ='+string(activation_freq)+' Hz')
    xlabel('time [s]')
    ylabel('Normalized Force')

    
end



    
    

