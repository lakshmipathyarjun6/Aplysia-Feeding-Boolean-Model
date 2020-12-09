close all
clear all

suffix = '_8_9_2020';
xlimits = [0 40];


%set initialization parameters for simulink model
aplysia = AplysiaSimulink();
simFileName = "Test"
aplysia.switchBehavior = 0;   %only behavior_1 is simulated 
aplysia.behavior_1 = double(FeedingBehavior.reject);
aplysia.behavior_2 = double(FeedingBehavior.reject);
aplysia.t_switch = 20; %time to switch

inargs.TimeStep=0.001;
inargs.EndTime=xlimits(2);
% end set initialization parameters

%Switches
USE_PURE_MATLAB_BIOMECHANICS = 0; %1 = use pure matlab biomechanics block.  0 = use simulink based biomechanics implementation.
USE_YU_I2_HILL_TYPE_MUSCLE_MODEL = 1; %1 = use Yu Hill Type Muscle Model.  0 = use original force model
%end switches

%initialize I2 Hill TYpe Muscle Model parameters
HTM_I2 = I2_Hill_Type_Muscle_Model();
%end initialize I2 Hill TYpe Muscle Model parameters

%run simulink model
aplysia = aplysia.runSimulation(inargs);
aplysia.generatePlots(['Swallow_' suffix],xlimits);
%end run simulink model

% yu_hillTypeMuscleModel = aplysia.outStruct.force_on_object.Data
% USE_YU_I2_HILL_TYPE_MUSCLE_MODEL = 0;
% aplysia = aplysia.runSimulation(inargs);
% OriginalModel = aplysia.outStruct.force_on_object.Data;


%%-----------------
%%compare to MATLAB
%%-----------------
aplysia_MATLAB = AplysiaFeeding_MATLAB(inargs );


t=aplysia_MATLAB.StartingTime:aplysia_MATLAB.TimeStep:aplysia_MATLAB.EndTime;
aplysia_MATLAB = aplysia_MATLAB.setSensoryStates('reject');
aplysia_MATLAB = aplysia_MATLAB.runSimulation();

figure()
hold on
plot(aplysia.outStruct.force_on_object.Time,aplysia.outStruct.force_on_object.Data,'k','LineWidth',2,'DisplayName','Simulink Model') %simulink
plot(t,aplysia_MATLAB.force_on_object,'b--','LineWidth',2, 'DisplayName', 'Original Boolean Model'); %MATLAB
%plot(aplysia.outStruct.force_on_object.Time,yu_hillTypeMuscleModel,'g','LineWidth',2,'DisplayName','Simulink Model') %simulink
xlabel('time (s)')
ylabel('Force on object')
legend()


% %%--------------
% %%Debug
% %%--------------
% fieldN = fieldnames(aplysia.outStruct);
% fieldN_MATLAB = fieldnames(aplysia_MATLAB);
% figure()
% for n = 1:length(fieldN_MATLAB)
%     val=aplysia_MATLAB.(fieldN_MATLAB{n});
%     if length(val)==1
%         val = repmat(val, length(t), 1);
%     end
%     plot(t,val','b-');
%     hold on
%     if isfield(aplysia.outStruct, fieldN_MATLAB{n})
%         plot(aplysia.outStruct.(fieldN_MATLAB{n}).Time,aplysia.outStruct.(fieldN_MATLAB{n}).Data,'k','LineWidth',2);
%     end
%     title(fieldN_MATLAB{n});
%     hold off
%     shg
% end