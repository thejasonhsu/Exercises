% The transfer function of a RL circuit is
% H(f) = J*2*pi*f*L /( R + j*(2*pi*f*L))
% This is the outputof the voltage across the inductor,
% The elts are in series
format long
R=1000;
L=1e-1;
logf=.0001:.1:10;
f=10.^logf;
w=2*pi*f;
H=1j*w*L./(R+(1i*w*L));
semilogx(f,20*log10(abs(H)))




% The transfer function of a RC circuit is
% H(f) = (-1i./(2*pi*f*C)) /( R -1i./(2*pi*f*C)) 
% The output is the voltage across the inductor,
% The elts are in series
format long
R=1000;
C=1e-6;
logf=.1:.01:5;
f=10.^logf;
w=2*pi*f;
H= 1./( 1 +(i*w*R*C));
semilogx(f,20*log10(abs(H)))

