%Excercise_117%
%Date: 09/17/2012
%Author: Jason Hsu

%%%%%%%%%%%
%Variables%
%%%%%%%%%%%
ascendaorta_d1=2.0;
ascendaorta_d2=3.2;
ascendaorta_v=63;

descendaorta_d1=1.6;
descendaorta_d2=2.0;
descendaorta_v=27;

artery_d1=0.2;
artery_d2=0.6;
artery_v1=20;
artery_v2=50;

capillary_d1=0.0005;
capillary_d2=0.001;
capillary_v1=0.05;
capillary_v2=0.1;

largevein_d1=0.5;
largevein_d2=1.0;
largevein_v1=15;
largevein_v2=20;

venaecavae_d=2.0;
venaecavae_v1=11;
venaecavae_v2=16;

density=1.056;
viscosity=0.040;
pi=3.14159265359;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Ascending Aorta Calculations%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
ascendaorta_volumetric1=(ascendaorta_d1/2)*(ascendaorta_d1/2)*pi*ascendaorta_v;
ascendaorta_volumetric2=(ascendaorta_d2/2)*(ascendaorta_d2/2)*pi*ascendaorta_v;
disp('volumetric flow of ascending aorta in cm^3/sec');
disp(ascendaorta_volumetric1);
disp('to')
disp(ascendaorta_volumetric2);

ascendaorta_massflow1=ascendaorta_volumetric1*density;
ascendaorta_massflow2=ascendaorta_volumetric2*density;
disp('mass flow rate of ascending aorta in g/s');
disp(ascendaorta_massflow1);
disp('to')
disp(ascendaorta_massflow2);

ascendaorta_reynold1=ascendaorta_d1*ascendaorta_v*density/1000/viscosity;
ascendaorta_reynold2=ascendaorta_d2*ascendaorta_v*density/1000/viscosity;
disp('Reynolds number for ascending aorta');
disp(ascendaorta_reynold1);
disp('to')
disp(ascendaorta_reynold2);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Descending Aorta Calculations%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
descendaorta_volumetric1=(descendaorta_d1/2)*(descendaorta_d1/2)*pi*descendaorta_v;
descendaorta_volumetric2=(descendaorta_d2/2)*(descendaorta_d2/2)*pi*descendaorta_v;
disp('volumetric flow of descending aorta in cm^3/sec');
disp(descendaorta_volumetric1);
disp('to')
disp(descendaorta_volumetric2);

descendaorta_massflow1=descendaorta_volumetric1*density;
descendaorta_massflow2=descendaorta_volumetric2*density;
disp('mass flow rate of descending aorta in g/s');
disp(descendaorta_massflow1);
disp('to')
disp(descendaorta_massflow2);

descendaorta_reynold1=descendaorta_d1*descendaorta_v*density/1000/viscosity;
descendaorta_reynold2=descendaorta_d2*descendaorta_v*density/1000/viscosity;
disp('Reynolds number for descending aorta');
disp(descendaorta_reynold1);
disp('to')
disp(descendaorta_reynold2);

%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Large Artery Calculations%
%%%%%%%%%%%%%%%%%%%%%%%%%%%
artery_volumetric1=(artery_d1/2)*(artery_d1/2)*pi*artery_v1;
artery_volumetric2=(artery_d2/2)*(artery_d2/2)*pi*artery_v2;
disp('volumetric flow of large artery in cm^3/sec');
disp(artery_volumetric1);
disp('to')
disp(artery_volumetric2);

artery_massflow1=artery_volumetric1*density;
artery_massflow2=artery_volumetric2*density;
disp('mass flow rate of large artery in g/s');
disp(artery_massflow1);
disp('to')
disp(artery_massflow2);

artery_reynold1=artery_d1*artery_v1*density/1000/viscosity;
artery_reynold2=artery_d2*artery_v2*density/1000/viscosity;
disp('Reynolds number for large artery');
disp(artery_reynold1);
disp('to')
disp(artery_reynold2);

%%%%%%%%%%%%%%%%%%%%%%%%
%Capillary Calculations%
%%%%%%%%%%%%%%%%%%%%%%%%
capillary_volumetric1=(capillary_d1/2)*(capillary_d1/2)*pi*capillary_v1;
capillary_volumetric2=(capillary_d2/2)*(capillary_d2/2)*pi*capillary_v2;
disp('volumetric flow of capillary in cm^3/sec');
disp(capillary_volumetric1);
disp('to')
disp(capillary_volumetric2);

capillary_massflow1=capillary_volumetric1*density;
capillary_massflow2=capillary_volumetric2*density;
disp('mass flow rate of capillary in g/s');
disp(capillary_massflow1);
disp('to')
disp(capillary_massflow2);

capillary_reynold1=capillary_d1*capillary_v1*density/1000/viscosity;
capillary_reynold2=capillary_d2*capillary_v2*density/1000/viscosity;
disp('Reynolds number for capillary');
disp(capillary_reynold1);
disp('to')
disp(capillary_reynold2);

%%%%%%%%%%%%%%%%%%%%%%%%%
%Large Vein Calculations%
%%%%%%%%%%%%%%%%%%%%%%%%%
largevein_volumetric1=(largevein_d1/2)*(largevein_d1/2)*pi*largevein_v1;
largevein_volumetric2=(largevein_d2/2)*(largevein_d2/2)*pi*largevein_v2;
disp('volumetric flow of large vein in cm^3/sec');
disp(largevein_volumetric1);
disp('to')
disp(largevein_volumetric2);

largevein_massflow1=largevein_volumetric1*density;
largevein_massflow2=largevein_volumetric2*density;
disp('mass flow rate of large vein in g/s');
disp(largevein_massflow1);
disp('to')
disp(largevein_massflow2);

largevein_reynold1=largevein_d1*largevein_v1*density/1000/viscosity;
largevein_reynold2=largevein_d2*largevein_v2*density/1000/viscosity;
disp('Reynolds number for large vein');
disp(largevein_reynold1);
disp('to')
disp(largevein_reynold2);

%%%%%%%%%%%%%%%%%%%%%%%%%
%Venae Cavae Calculations%
%%%%%%%%%%%%%%%%%%%%%%%%%
venaecavae_volumetric1=(venaecavae_d/2)*(venaecavae_d/2)*pi*venaecavae_v1;
venaecavae_volumetric2=(venaecavae_d/2)*(venaecavae_d/2)*pi*venaecavae_v2;
disp('volumetric flow of venae cavae in cm^3/sec');
disp(venaecavae_volumetric1);
disp('to')
disp(venaecavae_volumetric2);

venaecavae_massflow1=venaecavae_volumetric1*density;
venaecavae_massflow2=venaecavae_volumetric2*density;
disp('mass flow rate of venae cavae in g/s');
disp(venaecavae_massflow1);
disp('to')
disp(venaecavae_massflow2);

venaecavae_reynold1=venaecavae_d*venaecavae_v1*density/1000/viscosity;
venaecavae_reynold2=venaecavae_d*venaecavae_v2*density/1000/viscosity;
disp('Reynolds number for venae cavae');
disp(venaecavae_reynold1);
disp('to')
disp(venaecavae_reynold2);



