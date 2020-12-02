close all
clear all

suffix = '_8_9_2020';
xlimits = [0 40];

aplysia = AplysiaSimulink();
simFileName = "Test"
aplysia.switchBehavior = 0;   %only behavior_1 is simulated 
aplysia.behavior_1 = double(FeedingBehavior.swallow);
aplysia.behavior_2 = double(FeedingBehavior.reject);
aplysia.t_switch = 20; %time to switch
aplysia.stoptime = 40;

USE_PURE_MATLAB_BIOMECHANICS = 0; %1 = use pure matlab biomechanics block.  0 = use simulink based biomechanics implementation.

aplysia = aplysia.runSimulation();
aplysia.generatePlots(['Swallow_' suffix],xlimits);
