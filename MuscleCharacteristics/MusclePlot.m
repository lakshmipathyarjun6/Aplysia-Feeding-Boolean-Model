close all
%find I2 length - translation from interpolated figures in Neustadter 2002 Fig 18
opts = detectImportOptions('I2andBodyLength.xlsx');
M = readmatrix('I2andBodyLength.xlsx',opts);

M_BL=[M(find(~isnan(M(:,3))),3) , M(find(~isnan(M(:,3))),4)]; %remove NaN from BodyLength values

cycleP = [0:0.5:100];

fI2=fit(M(:,1),M(:,2),'fourier5'); %fit for I2
fI2_data = feval(fI2, cycleP); %data for I2

fBL=fit(M_BL(:,1),M_BL(:,2),'fourier5'); %fit for BodyLength
fBL_data = feval(fBL, cycleP); %data for BodyLength

protraction_limit = 44;
retraction_limit = 85;

protraction_fI2 = fI2_data(find(cycleP<=protraction_limit)); %I2 length
protraction_fBL = fBL_data(find(cycleP<=protraction_limit)); %Translation of the odontophore

retraction_fI2 = fI2_data(find(cycleP>=protraction_limit & cycleP<=retraction_limit)); %I2 length
retraction_fBL = fBL_data(find(cycleP>=protraction_limit & cycleP<=retraction_limit)); %Translation of the odontophore

loss_gamma_shape_fI2 = fI2_data(find(cycleP>=retraction_limit)); %I2 length
loss_gamma_shape_fBL = fBL_data(find(cycleP>=retraction_limit)); %Translation of the odontophore


figure()
plot(fI2)
xlabel('Cycle (%)')
ylabel('% of maximum I2 length change')

figure()
plot(fBL)
xlabel('Cycle (%)')
ylabel('% of Maximum Odontophore Translation')


%Plot retraction, protraction and loss of gamma shape data
figure()
subplot(3,1,1)
plot(protraction_fBL, protraction_fI2)
xlabel('% of Maximum Odontophore Translation')
ylabel('% of maximum I2 length change')
title("Protraction")

subplot(3,1,2)
plot(retraction_fBL , retraction_fI2 )
xlabel('% of Maximum Odontophore Translation')
ylabel('% of maximum I2 length change')
title("Retraction")

subplot(3,1,3)
plot(loss_gamma_shape_fBL, loss_gamma_shape_fI2)
xlabel('% of Maximum Odontophore Translation')
ylabel('% of maximum I2 length change')
title("Loss of \Gamma shape")


%split loss of gamma shape data based on inflection point

inflection_BL_length_change_ind = find(loss_gamma_shape_fBL == min(loss_gamma_shape_fBL));
inflection_BL_length_change = min(loss_gamma_shape_fBL);

inflect_protract_fI2 = loss_gamma_shape_fI2(inflection_BL_length_change_ind:end);
inflect_retract_fI2 = loss_gamma_shape_fI2(1:inflection_BL_length_change_ind);

inflect_protract_fBL = loss_gamma_shape_fBL(inflection_BL_length_change_ind:end );
inflect_retract_fBL = loss_gamma_shape_fBL (1:inflection_BL_length_change_ind);

new_protract_fI2 = normalize([protraction_fI2', inflect_protract_fI2']');
new_retract_fI2 = normalize([retraction_fI2', inflect_retract_fI2']');
new_protract = [new_protract_fBL, new_protract_fI2];
[~, idx] = unique(new_protract(:,1));
new_protract = new_protract(idx,:)

new_protract_fBL = normalize([protraction_fBL', inflect_protract_fBL']');
new_retract_fBL = normalize([retraction_fBL', inflect_retract_fBL']');
new_retract = [new_retract_fBL, new_retract_fI2];
[~, idx] = unique(new_retract(:,1));
new_retract = new_retract(idx,:)

figure()
subplot(2,1,1)
plot(new_protract_fBL, new_protract_fI2,'o')
title('protraction')
xlabel('% Translation')
ylabel('% I2 Length')



subplot(2,1,2)
plot(new_retract_fBL, new_retract_fI2,'o')
title('retraction')
xlabel('% Translation')
ylabel('% I2 Length')
s_retract = spline(new_retract(:,1), new_retract(:,2));

%fit data 
translation=[0:0.01:1];

%protract
s_protract = spline(new_protract(:,1), new_protract(:,2));

f_protract=fit(new_protract(:,1),new_protract(:,2),'fourier5'); %fit for I2
f_protract_data = feval(f_protract, translation); 
p_protract = polyfit(new_protract(:,1),new_protract(:,2),9);



%retract
s_retract = spline(new_retract(:,1), new_retract(:,2));

f_retract=fit(new_retract(:,1),new_retract(:,2),'fourier5'); %fit for I2
f_retract_data = feval(f_retract, translation); 
p_retract = polyfit(new_retract(:,1),new_retract(:,2),9);

figure()
subplot(2,1,1)
plot(translation, f_protract_data,'o')

subplot(2,1,2)
plot(translation, f_retract_data,'o')




function val = normalize(x)

    val=(x-min(x))./(max(x)-min(x));
    

end
