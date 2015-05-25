dt = 0.1;
duration = 100;
k1=1e6;
k2=1e-4;
Y=zeros(3,1);
Y(1,1)=4e-7;
Y(2,1)=3e-7;

for i = 1:(duration/dt)
    Y(1,i+1)=Y(1,i)-k1*dt*Y(1,i)*Y(2,i)+k2*dt*Y(3,i);
    Y(2,i+1)=Y(2,i)-k1*dt*Y(1,i)*Y(2,i)+k2*dt*Y(3,i);
    Y(3,i+1)=Y(3,i)+k1*dt*Y(1,i)*Y(2,i)-k2*dt*Y(3,i);
    Y(:,i+1)
end

t = 0:dt:duration;
figure;
plot(t,Y(1,:),'r');
hold on;
plot(t,Y(2,:),'b');
plot(t,Y(3,:),'g');
hold off