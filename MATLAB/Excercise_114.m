%Excercise_114%
%Date: 09/17/2012
%Author: Jason Hsu

%%%%%%%%%%%
%Variables%
%%%%%%%%%%%
percent_Ti=80;
percent_Al=13;
percent_V=7;
molarmass_Ti=204.38;
molarmass_Al=26.98;
molarmass_V=50.94;

%%%%%%%%%%%%%%
%Calculations%
%%%%%%%%%%%%%%
massfraction_Ti=percent_Ti/100;
massfraction_Al=percent_Al/100;
massfraction_V=percent_V/100;
disp('mass fraction of Ti');
disp(massfraction_Ti);
disp('mass fraction of Al');
disp(massfraction_Al);
disp('mass fraction of V');
disp(massfraction_V);

moles_Ti=massfraction_Ti/molarmass_Ti;
moles_Al=massfraction_Al/molarmass_Al;
moles_V=massfraction_V/molarmass_V;

totalmoles=moles_Ti+moles_Al+moles_V;

molefraction_Ti=moles_Ti/totalmoles;
molefraction_Al=moles_Al/totalmoles;
molefraction_V=moles_V/totalmoles;

disp('mole fraction of Ti');
disp(molefraction_Ti);
disp('mole fraction of Al');
disp(molefraction_Al);
disp('mole fraction of V');
disp(molefraction_V);

average_molecularmass=molefraction_Ti*molarmass_Ti+molefraction_Al*molarmass_Al+molefraction_V*molarmass_V;
disp('average molecular weight in g/mol');
disp(average_molecularmass);









