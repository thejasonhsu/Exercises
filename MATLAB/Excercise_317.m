%Excercise_317%
%Date: 10/5/2012
%Author: Jason Hsu

%%%%%%
%Data%
%%%%%%
A = [0.60 0.20 0.20 0; 0.20 0.60 0 0.20; 0.20 0 0.60 0.20; 0 0.20 0.20 0.60];
T1 = [0.25; 0.25; 0.25; 0.25];
T2 = [0.35; 0.3; 0.2; 0.15];
T3 = [0.4; 0.3; 0.2; 0.1];
m_flowrate=10000;

%%%%%%%%
%Part A%
%%%%%%%%
x1 = [A\T1];
x2 = [A\T2];
x3 = [A\T3];

disp('Part A')

m_flowrate_x1a1=m_flowrate*(x1(1,1))/(x1(1,1)+x1(2,1)+x1(3,1)+x1(4,1));
disp('mass flow rate of t1 a1 in lbm/hr');
disp(m_flowrate_x1a1);

m_flowrate_x1a2=m_flowrate*(x1(2,1))/(x1(1,1)+x1(2,1)+x1(3,1)+x1(4,1));
disp('mass flow rate of t1 a2 in lbm/hr');
disp(m_flowrate_x1a2);

m_flowrate_x1a3=m_flowrate*(x1(3,1))/(x1(1,1)+x1(2,1)+x1(3,1)+x1(4,1));
disp('mass flow rate of t1 a3 in lbm/hr');
disp(m_flowrate_x1a3);

m_flowrate_x1a4=m_flowrate*(x1(4,1))/(x1(1,1)+x1(2,1)+x1(3,1)+x1(4,1));
disp('mass flow rate of t1 a4 in lbm/hr');
disp(m_flowrate_x1a4);


m_flowrate_x2a1=m_flowrate*(x2(1,1))/(x2(1,1)+x2(2,1)+x2(3,1)+x2(4,1));
disp('mass flow rate of t2 a1 in lbm/hr');
disp(m_flowrate_x2a1);

m_flowrate_x2a2=m_flowrate*(x2(2,1))/(x2(1,1)+x2(2,1)+x2(3,1)+x2(4,1));
disp('mass flow rate of t2 a2 in lbm/hr');
disp(m_flowrate_x2a2);

m_flowrate_x2a3=m_flowrate*(x2(3,1))/(x2(1,1)+x2(2,1)+x2(3,1)+x2(4,1));
disp('mass flow rate of t2 a3 in lbm/hr');
disp(m_flowrate_x2a3);

m_flowrate_x2a4=m_flowrate*(x2(4,1))/(x2(1,1)+x2(2,1)+x2(3,1)+x2(4,1));
disp('mass flow rate of t2 a4 in lbm/hr');
disp(m_flowrate_x2a4);


m_flowrate_x3a1=m_flowrate*(x3(1,1))/(x3(1,1)+x3(2,1)+x3(3,1)+x3(4,1));
disp('mass flow rate of t3 a1 in lbm/hr');
disp(m_flowrate_x3a1);

m_flowrate_x3a2=m_flowrate*(x3(2,1))/(x3(1,1)+x3(2,1)+x3(3,1)+x3(4,1));
disp('mass flow rate of t3 a2 in lbm/hr');
disp(m_flowrate_x3a2);

m_flowrate_x3a3=m_flowrate*(x3(3,1))/(x3(1,1)+x3(2,1)+x3(3,1)+x3(4,1));
disp('mass flow rate of t3 a3 in lbm/hr');
disp(m_flowrate_x3a3);

m_flowrate_x3a4=m_flowrate*(x3(4,1))/(x3(1,1)+x3(2,1)+x3(3,1)+x3(4,1));
disp('mass flow rate of t3 a4 in lbm/hr');
disp(m_flowrate_x3a4);

%%%%%%%%
%Part B%
%%%%%%%%

disp('Part B')

Ab1 = [0.60 0.20 0.20 0; 0.20 0.60 0 0.20];

syms x;
S = solve(0.60*x+0.20*(1-x)-0.50);
display('Mass flow of Alloy Feed 1 if Target Alloy 1 has a rate of 1 lbm/hr');
display(S);
display('Mass flow of Alloy Feed 2 if Target Alloy 1 has a rate of 1 lbm/hr');
display(1-S);

disp('M1 = [0.50 0.30 0.15 0.05]');
disp('A5 = [F 0 0.5*F K]');
disp('M2 = [0.40 G G K]'); 

disp('0.50+F*Y=0.40*(1+Y)');
disp('0.30=G*(1+Y)');
disp('0.15+0.5*F*Y=G*(1+Y)');
disp('0.05+K*Y=K*(1+Y)');

disp('0.15=0.5*F*Y');
disp('F*Y=0.3');
disp('(0.50+0.3)/0.40=1+Y');
disp('1=Y');
disp('Mass flow of M1 over total = 1/2');
disp('Mass flow of A5 over total = 1/2');
disp(' ');

syms AF;
A5F = solve(0.50*(1/2)+AF*(1/2)-0.40);
disp('Mass flow of F in Alloy Feed 5 when M1 has a rate of 1 lbm/hr');
disp(A5F); 

syms AH;
A5H = solve(0.5*3/10-AH);
disp('Mass flow of H in Alloy Feed 5 when M1 has a rate of 1 lbm/hr');
disp(A5H);

syms AK;
A5K = solve(1-3/10-3/20-AK);
disp('Mass flow of K in Alloy Feed 5 when M1 has a rate of 1 lbm/hr');
disp(A5K);

syms G;
M2G = solve(0.3*1/2-G);
M2H = solve(0.3*1/2-G);
disp('Mass flow of G in M2 when M1 has a rate of 1 lbm/hr');
disp(M2G);
disp('Mass flow of H in M2 when M1 has a rate of 1 lbm/hr');
disp(M2H);

syms K;
M2K = solve(0.05*(1/2)+(11/20)*(1/2)-K);
disp('Mass flow of K in M2 when M1 has a rate of 1 lbm/hr');
disp(M2K);

disp('Mass flow of F in M2 when M1 has a rate of 10000 lbm/hr');
disp(0.40*10000);

disp('Mass flow of G in M2 when M1 has a rate of 10000 lbm/hr');
disp(M2G*10000);

disp('Mass flow of H in M2 when M1 has a rate of 10000 lbm/hr');
disp(M2H*10000);

disp('Mass flow of K in M2 when M1 has a rate of 10000 lbm/hr');
disp(M2K*10000);



