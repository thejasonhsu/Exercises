function ee150_protonbeam_1plot(v0, B, Ei, dE, Ef)
for E=Ei:dE:Ef
dt=1e-9;
a=0;
b=10e-6;
q=1.602e-19;
m=1.672e-27;
w=q*B/m;
a_e=q*E/m;
j=(b-a)/dt;
v=zeros(1,j+1);
x=zeros(1,j+1);
v(1,1)=v0;
x(1,1)=0;
v(2,1)=0;
x(2,1)=0;
for i=1:j
v(1,i+1)=v(1,i)+w*v(2,i)*dt;
v(2,i+1)=v(2,i)+(-w*v(1,i)+a_e)*dt;
x(1,i+1)=x(1,i)+v(1,i)*dt;
x(2,i+1)=x(2,i)+v(2,i)*dt;
end
if abs(v(2,i)) < 0.5
figure
plot(x(1,:),x(2,:))
title(['Trajectory for E = ' int2str(E) ' V/m'])
xlabel('X-Pos (m)')
ylabel('Y-Pos (m)')
grid
axis([-0.2 0.2 -0.1 0.1]);
end
end