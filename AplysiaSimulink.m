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
            init_obj.force_on_object = 0;

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
            "grasper_friction_state", "jaw_friction_state", "seaweed_strength", "fixation_type", "force_on_object",...
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
        
        
        
        function obj = runSimulation(obj )
            obj.init_obj = obj.initializeStruct( obj.switchBehavior, double(obj.behavior_1), double(obj.behavior_2), obj.t_switch); 
            obj.AplysiaBus = obj.initializeBus();   
            assignin('base','AplysiaBus',obj.AplysiaBus)
            assignin('base','init_obj',obj.init_obj)
            out = sim(obj.simFileName,'StartTime','0','StopTime',string(obj.stoptime), 'FixedStep', string(obj.init_obj.TimeStep));
            outStruct = out.outputStruct;  
            obj.outStruct = out.outputStruct
        end
        
        
%         function obj = AplysiaSimulink( switchBehavior, behavior_1, behavior_2, t_switch)
%             obj.init_obj = obj.initializeStruct( switchBehavior, double(behavior_1), double(behavior_2), t_switch); 
%             obj.AplysiaBus = obj.initializeBus();   
%             assignin('base','AplysiaBus',obj.AplysiaBus)
%             assignin('base','init_obj',obj.init_obj)
%             
%         end



        function generatePlots(obj,label,xlimits)
            %t=obj.StartingTime:obj.TimeStep:obj.EndTime;
            ps= obj.outStruct

            figure('Position', [10 10 1200 600]);
            set(gcf,'Color','white')
            xl=xlimits; % show full time scale
            ymin = 0;
            ymax = 1;
            shift = 0.0475;%0.04;
            top = 0.95;
            i=0;
            left = 0.25;
            width = 0.7;
            height = 0.02;

            subplot(15,1,1)
            %External Stimuli
            subplot('position',[left top width height])
            i=i+1;
            plot(ps.sens_mechanical_grasper.Time,ps.sens_mechanical_grasper.Data, 'Color', [56/255, 232/255, 123/255],'LineWidth',2) %mechanical in grasper
            set(gca,'FontSize',16)

            set(gca,'xtick',[])
            set(gca,'ytick',[0,1])
            set(gca,'YTickLabel',[]);
            ylabel('Mech. in Grasper')
            ylim([0 1])
            grid on
            xlim(xl)
            hYLabel = get(gca,'YLabel');
            set(hYLabel,'rotation',0,'VerticalAlignment','middle','HorizontalAlignment','right','Position',get(hYLabel,'Position')-[0.05 0 0])

            set(gca,'XColor','none')

            subplot('position',[left top-i*shift width height])
            i=i+1;
            plot(ps.sens_chemical_lips.Time,ps.sens_chemical_lips.Data, 'Color', [70/255, 84/255, 218/255],'LineWidth',2) %chemical at lips
            set(gca,'FontSize',16)
            set(gca,'xtick',[])
            set(gca,'ytick',[0,1])
            set(gca,'YTickLabel',[]);
            ylabel('Chem. at Lips')
            ylim([0 1])
            grid on
            xlim(xl)
            hYLabel = get(gca,'YLabel');
            set(hYLabel,'rotation',0,'VerticalAlignment','middle','HorizontalAlignment','right','Position',get(hYLabel,'Position')-[0.05 0 0])

            set(gca,'XColor','none')

            subplot('position',[left top-i*shift width height])
            i=i+1;
            plot(ps.sens_mechanical_lips.Time,ps.sens_mechanical_lips.Data, 'Color', [47/255, 195/255, 241/255],'LineWidth',2) %mechanical at lips
            set(gca,'FontSize',16)
            set(gca,'xtick',[])
            set(gca,'ytick',[0,1])
            set(gca,'YTickLabel',[]);
            ylabel('Mech. at Lips')
            ylim([0 1])
            grid on
            xlim(xl)
            hYLabel = get(gca,'YLabel');
            set(hYLabel,'rotation',0,'VerticalAlignment','middle','HorizontalAlignment','right','Position',get(hYLabel,'Position')-[0.05 0 0])
            set(gca,'XColor','none')


            subplot('position',[left top-i*shift width height])
            plot(ps.CBI2.Time,ps.CBI2.Data,'k','LineWidth',2) % CBI2
            i=i+1;
            set(gca,'FontSize',16)
            set(gca,'xtick',[])
            set(gca,'ytick',[0,1])
            set(gca,'YTickLabel',[]);
            ylabel('CBI-2')
            ylim([ymin ymax])
            xlim(xl)
            hYLabel = get(gca,'YLabel');
            set(hYLabel,'rotation',0,'VerticalAlignment','middle','HorizontalAlignment','right','Position',get(hYLabel,'Position')-[0.05 0 0])
            set(gca,'XColor','none')


            subplot('position',[left top-i*shift width height])
            plot(ps.CBI3.Time,ps.CBI3.Data,'k','LineWidth',2) % CBI3
            i=i+1;
            set(gca,'FontSize',16)
            set(gca,'xtick',[])
            set(gca,'ytick',[0,1])
            set(gca,'YTickLabel',[]);
            ylabel('CBI-3')
            ylim([ymin ymax])
            xlim(xl)
            hYLabel = get(gca,'YLabel');
            set(hYLabel,'rotation',0,'VerticalAlignment','middle','HorizontalAlignment','right','Position',get(hYLabel,'Position')-[0.05 0 0])
            set(gca,'XColor','none')


            subplot('position',[left top-i*shift width height])
            plot(ps.CBI4.Time,ps.CBI4.Data,'k','LineWidth',2) % CBI4
            i=i+1;
            set(gca,'FontSize',16)
            set(gca,'xtick',[])
            set(gca,'ytick',[0,1])
            set(gca,'YTickLabel',[]);
            ylabel('CBI-4')
            ylim([ymin ymax])
            xlim(xl)
            hYLabel = get(gca,'YLabel');
            set(hYLabel,'rotation',0,'VerticalAlignment','middle','HorizontalAlignment','right','Position',get(hYLabel,'Position')-[0.05 0 0])
            set(gca,'XColor','none')

            %Interneurons
            subplot('position',[left top-i*shift width height])
            plot(ps.B64.Time,ps.B64.Data,'LineWidth',2, 'Color',[90/255, 131/255, 198/255]) % B64
            i=i+1;
            set(gca,'FontSize',16)
            set(gca,'xtick',[])
            set(gca,'ytick',[0,1])
            set(gca,'YTickLabel',[]);
            ylabel('B64', 'Color',[90/255, 131/255, 198/255])
            ylim([ymin ymax])
            xlim(xl)
            hYLabel = get(gca,'YLabel');
            set(hYLabel,'rotation',0,'VerticalAlignment','middle','HorizontalAlignment','right','Position',get(hYLabel,'Position')-[0.05 0 0])
            set(gca,'XColor','none')


            subplot('position',[left top-i*shift width height])
            plot(ps.B20.Time,ps.B20.Data,'LineWidth',2, 'Color',[44/255, 166/255, 90/255]) % B20
            i=i+1;
            set(gca,'FontSize',16)
            set(gca,'xtick',[])
            set(gca,'ytick',[0,1])
            set(gca,'YTickLabel',[]);
            ylabel('B20', 'Color',[44/255, 166/255, 90/255])
            ylim([ymin ymax])
            xlim(xl)
            hYLabel = get(gca,'YLabel');
            set(hYLabel,'rotation',0,'VerticalAlignment','middle','HorizontalAlignment','right','Position',get(hYLabel,'Position')-[0.05 0 0])
            set(gca,'XColor','none')


            subplot('position',[left top-i*shift width height])
            plot(ps.B40B30.Time,ps.B40B30.Data,'LineWidth',2, 'Color',[192/255, 92/255, 185/255]) % B40/B30
            i=i+1.5;
            set(gca,'FontSize',16)
            set(gca,'xtick',[])
            set(gca,'ytick',[0,1])
            set(gca,'YTickLabel',[]);
            ylabel('B40/B30', 'Color',[192/255, 92/255, 185/255])
            ylim([ymin ymax])
            xlim(xl)
            hYLabel = get(gca,'YLabel');
            set(hYLabel,'rotation',0,'VerticalAlignment','middle','HorizontalAlignment','right','Position',get(hYLabel,'Position')-[0.05 0 0])
            set(gca,'XColor','none')


            subplot('position',[left top-i*shift width height*2])
            plot(ps.B4B5.Time,ps.B4B5.Data,'LineWidth',2, 'Color', [51/255, 185/255, 135/255]) % B4/5
            i=i+1;
            set(gca,'FontSize',16)
            set(gca,'xtick',[])
            set(gca,'ytick',[0,1,2])
            set(gca,'YTickLabel',[]);
            ylabel('B4/B5', 'Color', [51/255, 185/255, 135/255])
            ylim([ymin 2])
            xlim(xl)
            hYLabel = get(gca,'YLabel');
            set(hYLabel,'rotation',0,'VerticalAlignment','middle','HorizontalAlignment','right','Position',get(hYLabel,'Position')-[0.05 0 0])
            set(gca,'XColor','none')


            %motor neurons
            subplot('position',[left top-i*shift width height])
            plot(ps.B31B32.Time,ps.B31B32.Data,'LineWidth',2, 'Color', [220/255, 81/255, 81/255]) % I2 input
            i=i+1;
            set(gca,'FontSize',16)
            set(gca,'xtick',[])
            set(gca,'ytick',[0,1])
            set(gca,'YTickLabel',[]);
            ylabel('B31/B32','Color',[220/255, 81/255, 81/255])
            ylim([ymin ymax])
            xlim(xl)
            hYLabel = get(gca,'YLabel');
            set(hYLabel,'rotation',0,'VerticalAlignment','middle','HorizontalAlignment','right','Position',get(hYLabel,'Position')-[0.05 0 0])
            set(gca,'XColor','none')


            subplot('position',[left top-i*shift width height])
            plot(ps.B8.Time,ps.B8.Data,'LineWidth',2, 'Color', [213/255, 155/255, 196/255]) % B8a/b
            i=i+1;
            set(gca,'FontSize',16)
            set(gca,'xtick',[])
            set(gca,'ytick',[0,1])
            set(gca,'YTickLabel',[]);
            ylabel('B8a/b', 'Color', [213/255, 155/255, 196/255])
            ylim([ymin ymax])
            xlim(xl)
            hYLabel = get(gca,'YLabel');
            set(hYLabel,'rotation',0,'VerticalAlignment','middle','HorizontalAlignment','right','Position',get(hYLabel,'Position')-[0.05 0 0])
            set(gca,'XColor','none')


            subplot('position',[left top-i*shift width height])
            plot(ps.B38.Time,ps.B38.Data,'LineWidth',2, 'Color', [238/255, 191/255, 70/255]) % B38
            i=i+1;
            set(gca,'FontSize',16)
            set(gca,'xtick',[])
            set(gca,'ytick',[0,1])
            set(gca,'YTickLabel',[]);
            ylabel('B38', 'Color', [238/255, 191/255, 70/255])
            ylim([ymin ymax])
            xlim(xl)
            hYLabel = get(gca,'YLabel');
            set(hYLabel,'rotation',0,'VerticalAlignment','middle','HorizontalAlignment','right','Position',get(hYLabel,'Position')-[0.05 0 0])
            set(gca,'XColor','none')


            subplot('position',[left top-i*shift width height])
            plot(ps.B6B9B3.Time,ps.B6B9B3.Data,'LineWidth',2, 'Color', [90/255, 155/255, 197/255]) % B6/9/3
            i=i+1;
            set(gca,'FontSize',16)
            set(gca,'xtick',[])
            set(gca,'ytick',[0,1])
            set(gca,'YTickLabel',[]);
            ylabel('B6/B9/B3', 'Color', [90/255, 155/255, 197/255])
            ylim([ymin ymax])
            xlim(xl)
            set(get(gca,'ylabel'),'rotation',0) 
            hYLabel = get(gca,'YLabel');
            set(hYLabel,'rotation',0,'VerticalAlignment','middle','HorizontalAlignment','right','Position',get(hYLabel,'Position')-[0.05 0 0])
            set(gca,'XColor','none')


            subplot('position',[left top-i*shift width height])
            plot(ps.B7.Time,ps.B7.Data,'LineWidth',2, 'Color', [56/255, 167/255, 182/255]) % B7
            i=i+2.5;
            set(gca,'FontSize',16)
            set(gca,'xtick',[])
            set(gca,'ytick',[0,1])
            set(gca,'YTickLabel',[]);
            ylabel('B7', 'Color', [56/255, 167/255, 182/255])
            ylim([ymin ymax])
            xlim(xl)
            hYLabel = get(gca,'YLabel');
            set(hYLabel,'rotation',0,'VerticalAlignment','middle','HorizontalAlignment','right','Position',get(hYLabel,'Position')-[0.05 0 0])
            set(gca,'XColor','none')


            %Determine locations of protraction retraction boxes
            tstep = obj.init_obj.TimeStep;
            startnum = round(xl(1)/tstep);
            endnum = round(xl(2)/tstep);
            grasper_rel_pos = (ps.x_g.Data-ps.x_h.Data);
            numProtractionBoxes = 0;
            numRetractionBoxes = 0;
            protraction = 1;
            protractionRectangles=[0,0];
            retractionRectangles=[0,0];
            for ind=startnum+2:endnum
            if grasper_rel_pos(ind) > grasper_rel_pos(ind-1)
                %protraction
                if(protraction == 0)
                    numProtractionBoxes=numProtractionBoxes+1;
                    protraction = 1;
                    %end the last retractionrectangle
                    if(numRetractionBoxes>0)
                        retractionRectangles(numRetractionBoxes,2) = ind;
                    end
                    %start a new protractionrectangle
                    protractionRectangles(numProtractionBoxes,1) = ind;
                end
            else
                %retraction
                if(protraction == 1)
                    numRetractionBoxes=numRetractionBoxes+1;
                    protraction = 0;
                    %end the last retractionrectangle            
                    retractionRectangles(numRetractionBoxes,1) = ind;
                    %start a new protractionrectangle
                    if(numProtractionBoxes>0)
                        protractionRectangles(numProtractionBoxes,2) = ind; 
                    end
                end     
            end
            end

            if retractionRectangles(end,2) ==0
             retractionRectangles(end,2) = endnum;
            end

            if protractionRectangles(end,2) ==0
             protractionRectangles(end,2) = endnum;
            end

            %Grasper Motion
            subplot('position',[left top-i*shift width height*3.5])
            grasper_motion = (ps.x_g.Data-ps.x_h.Data);
            grasper_pressure = ps.grasper_friction_state.Data;
            idx = grasper_pressure >=1;%pmax*0.6;
            idy = grasper_pressure <1;%pmax*0.6;

            grasper_motion_pressure(idx) = grasper_motion(idx);
            grasper_motion_pressure(idy)=NaN;

            plot(ps.grasper_friction_state.Time,grasper_motion_pressure,'b','LineWidth',4)
            hold on
            plot(ps.grasper_friction_state.Time,grasper_motion,'b','LineWidth',2)
            hold off

            i=i+2.5;
            set(gca,'FontSize',16)
            set(gca,'xtick',[])
            set(gca,'YTickLabel',[]);
            ylabel({'Grasper';'Motion'}, 'Color', [0/255, 0/255, 255/255])
            xlim(xl)
            set(gca,'XColor','none')
            hYLabel = get(gca,'YLabel');
            set(hYLabel,'rotation',0,'VerticalAlignment','middle','HorizontalAlignment','right','Position',get(hYLabel,'Position')-[0.05 0 0])
            set(gca,'XColor','none')

            hold on
            for retract = 1:length(retractionRectangles)
                h=rectangle('Position', [retractionRectangles(retract,1)*tstep 1.25 (retractionRectangles(retract,2)-retractionRectangles(retract,1))*tstep 0.1]);  
                h.FaceColor = 'black';
            end
            hold off

            hold on
            for protract = 1:length(protractionRectangles)
                h=rectangle('Position', [protractionRectangles(protract,1)*tstep 1.25 (protractionRectangles(protract,2)-protractionRectangles(protract,1))*tstep 0.1]);  
                h.FaceColor = 'white';
            end
            hold off


            %subplot(15,1,15)
            subplot('position',[left top-i*shift width height*3.5])

            plot(ps.force_on_object.Time,ps.force_on_object.Data,'k','LineWidth',2)
            yticks([-1 0 1])
            yticklabels({'','0',''})

            set(gca,'FontSize',16)
            set(gca,'xtick',[])
            ylabel('Force', 'Color', [0/255, 0/255, 0/255])
            xlim(xl)
            set(gca,'XColor','none')
            hYLabel = get(gca,'YLabel');
            set(hYLabel,'rotation',0,'VerticalAlignment','middle','HorizontalAlignment','right','Position',get(hYLabel,'Position')-[0.05 0 0])
            set(gca,'XColor','none')

            if ~exist('fig', 'dir')
                mkdir('fig');
            end
            saveas(gcf,['fig/' label '_all.png'])            
        end
        
        
        
        
        
        
    end
    
end


    



