function [y] = transfusion3(RBCA, RBCB)
%solves for the mass of y

md=1; %mass of final pack

WA=0.025; %WBC in A
IA=(0.975-RBCA); %ISO in A
PA=0; %PROTEIN in A

WB=0.01; %WBC in B
IB=.18; %ISO in B
PB=(0.81-RBCB); %PROTEIN in B

WC=0; %WBC in C
PC=0; %PROTEIN in C
RC=0; %RBC in C
IC=1; %ISO in C

C=[0.025 0.01 0 0 0; 0 (0.81-RBCB) 0 0 0; IA 0.18 1 0 -1; RBCA RBCB 0 -1 0; 1 1 1 0 0; 0 0 0 1 1];
sol=[.02; .126; 0; 0; 1; .854];

Out=C\sol;
y=Out(4);



