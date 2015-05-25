%Excercise_125%
%Date: 10/01/2012
%Author: Jason Hsu

%%%%%%
%Data%
%%%%%%
C = [6 12 18 24 30]
A1 = [55.55 57.01 57.95]
A2 = [110.66 114.76 113.05]
A3 = [168.9 169.44 176.55]
A4 = [233.66 233.89 230.67]
A5 = [300.45 304.56 301.11]
A_av = [mean(A1) mean(A2) mean(A3) mean(A4) mean(A5)]

%%%%%%%%%%%%%%
%Calculations%
%%%%%%%%%%%%%%
disp('mean peak area when C=6')
disp(mean(A1))
disp('standard deviation when C=6')
disp(std(A1))

disp('mean peak area when C=12')
disp(mean(A2))
disp('standard deviation when C=12')
disp(std(A2))

disp('mean peak area when C=18')
disp(mean(A3))
disp('standard deviation when C=18')
disp(std(A3))

disp('mean peak area when C=24')
disp(mean(A4))
disp('standard deviation when C=24')
disp(std(A4))

disp('mean peak area when C=30')
disp(mean(A5))
disp('standard deviation when C=30')
disp(std(A5))

plot(C, A_av, '-.r*');
xlabel('Sucrose concentration in g/L');
ylabel('Mean Peak Area');
title('Chromatogram Peak Areas of Sucrose Concentrations');

Sol = polyfit(C, A_av, 1);
disp('slope, intersect of linear model');
disp(Sol);

y = [10.1721*C-7.8830];

hold on;
plot(C,y);

%%%%%%%%%%%
%Solutions%
%%%%%%%%%%%
disp('equation for peak area as a function of sucrose concentration');
disp('A(C) = 10.1721*C -7.8830');

syms x;
disp('sucrose concentration when peak area is 209.86');
solve(10.1721*x - 7.8830 - 209.86, x);
disp('or');
disp(double(119705480183414784/5592171114450125));

