%Excercise_116%
%Date: 09/17/2012
%Author: Jason Hsu

%%%%%%%%%%%
%Variables%
%%%%%%%%%%%
trachea_radius=1.0;
trachea_airflow=110;
bronchi_radius=0.45;
bronchi_airflow=11;
air_density=1.29;
massfraction_oxygen=0.21;
massfraction_nitrogen=0.79;
viscosity=1.84e-4;
molarmass_o2=32;
molarmass_n2=28;
pi=3.14159265359;

%%%%%%%%%%%%%%%%%%%%%%
%Volumetric Flow Rate%
%%%%%%%%%%%%%%%%%%%%%%
volumetricflowrate_trachea=trachea_radius*trachea_radius*pi*trachea_airflow;
disp('volumetric flow rate of trachea in mL/sec');
disp(volumetricflowrate_trachea);
volumetricflowrate_bronchi=bronchi_radius*bronchi_radius*pi*bronchi_airflow;
disp('volumetric flow rate of bronchi in mL/sec');
disp(volumetricflowrate_bronchi);

%%%%%%%%%%%%%%%%
%Mass Flow Rate%
%%%%%%%%%%%%%%%%
massflowrate_trachea=volumetricflowrate_trachea/1000*air_density;
disp('mass flow rate of trachea in g/sec');
disp(massflowrate_trachea);
massflowrate_bronchi=volumetricflowrate_bronchi/1000*air_density;
disp('mass flow rate of bronchi in g/sec');
disp(massflowrate_bronchi);

%%%%%%%%%%%%%%%%%
%Molar Flow Rate%
%%%%%%%%%%%%%%%%%
molarflowrate_trachea_o2=massflowrate_trachea*massfraction_oxygen/molarmass_o2;
molarflowrate_trachea_n2=massflowrate_trachea*massfraction_nitrogen/molarmass_n2;
molarflowrate_trachea=molarflowrate_trachea_o2+molarflowrate_trachea_n2;
disp('molar flow rate of trachea in mol/sec');
disp(molarflowrate_trachea);

molarflowrate_bronchi_o2=massflowrate_bronchi*massfraction_oxygen/molarmass_o2;
molarflowrate_bronchi_n2=massflowrate_bronchi*massfraction_nitrogen/molarmass_n2;
molarflowrate_bronchi=molarflowrate_bronchi_o2+molarflowrate_trachea_n2;
disp('molar flow rate of bronchi in mol/sec');
disp(molarflowrate_bronchi);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Reynold's Number Calculations%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
reynold_trachea=trachea_radius*2*trachea_airflow*air_density/1000/viscosity;
disp('Reynolds number for trachea');
disp(reynold_trachea);

reynold_bronchi=bronchi_radius*2*bronchi_airflow*air_density/1000/viscosity;
disp('Reynolds number for bronchi');
disp(reynold_bronchi);




