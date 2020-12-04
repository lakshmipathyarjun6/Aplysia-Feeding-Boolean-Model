close all
clear all

suffix = '_8_9_2020';
xlimits = [0 80];

aplysia = AplysiaSimulink();
simFileName = "Test"
aplysia.switchBehavior = 0;   %only behavior_1 is simulated 
aplysia.behavior_1 = double(FeedingBehavior.reject);
aplysia.behavior_2 = double(FeedingBehavior.reject);
aplysia.t_switch = 20; %time to switch

USE_PURE_MATLAB_BIOMECHANICS = 1; %1 = use pure matlab biomechanics block.  0 = use simulink based biomechanics implementation.
inargs.TimeStep=0.050;
inargs.EndTime=xlimits(2);


aplysia = aplysia.runSimulation(inargs);
aplysia.generatePlots(['Swallow_' suffix],xlimits);


%%-----------------
%%compare to MATLAB
%%-----------------
aplysia_MATLAB = AplysiaFeeding_MATLAB(inargs );


t=aplysia_MATLAB.StartingTime:aplysia_MATLAB.TimeStep:aplysia_MATLAB.EndTime;
aplysia_MATLAB = aplysia_MATLAB.setSensoryStates('reject');
aplysia_MATLAB = aplysia_MATLAB.runSimulation();

figure()
hold on
plot(aplysia.outStruct.force_on_object.Time,aplysia.outStruct.force_on_object.Data,'k','LineWidth',2) %simulink
plot(t,aplysia_MATLAB.force_on_object,'b--','LineWidth',2); %MATLAB



%%--------------
%%Debug
%%--------------
fieldN = fieldnames(aplysia.outStruct);
fieldN_MATLAB = fieldnames(aplysia_MATLAB);
figure()
for n = 1:length(fieldN_MATLAB)
    val=aplysia_MATLAB.(fieldN_MATLAB{n});
    if length(val)==1
        val = repmat(val, length(t), 1);
    end
    plot(t,val','b-');
    hold on
    if isfield(aplysia.outStruct, fieldN_MATLAB{n})
        plot(aplysia.outStruct.(fieldN_MATLAB{n}).Time,aplysia.outStruct.(fieldN_MATLAB{n}).Data,'k','LineWidth',2);
    end
    title(fieldN_MATLAB{n});
    hold off
    shg
end