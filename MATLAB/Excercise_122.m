%Excercise_122%
%Date: 10/01/2012
%Author: Jason Hsu

%%%%%%
%Data%
%%%%%%
W = [100 110 225 275 375 550 750 825 950 1200 1400 1700];
Cons = [0.55 0.45 0.55 0.75 0.95 1.25 1.82 2.05 2.10 2.75 3.00 3.75];

%%%%%%%%%%%%%%
%Calculations%
%%%%%%%%%%%%%%
plot(W,Cons,'-.r*')
xlabel('Work Output (kg*m/min)')
ylabel('Oxygen Consumption (L/min)')
legend('data from 07/01/2008')
title('Oxygen consumption of an astronaut')

ModelCons = [0.0021*W+0.21];
hold on;
plot(W,ModelCons)