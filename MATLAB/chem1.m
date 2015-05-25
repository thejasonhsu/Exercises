dt=0.1;
t=100;
y1=5e-7;
y2=2e-7;
y3=0;
y4=0;
k1=1e6;
k2=1e-4;
k3=1e-1;
A(1,1)=y1;
A(2,1)=y2;
A(3,1)=y3;
A(4,1)=y4;
totalt=t/dt;
for i=1:totalt
    A(1,i+1)=A(1,i)+(-k1*A(1,i)*A(2,i)+k2*A(3,i))*dt;
    A(2,i+1)=A(2,i)+(-k2*A(1,i)*A(2,i)+(k2+k3)*A(3,i))*dt;
    A(3,i+1)=A(3,i)+(k1*A(1,i)*A(2,i)-(k2+k3)*A(3,i))*dt;
    A(4,i+1)=A(4,i)+(k3*A(3,i))*dt
end

figure;
hold on
plot(0:dt:t, A(1, 1:i+1), 'r');
plot(0:dt:t, A(2, 1:i+1), 'b');
plot(0:dt:t, A(3, 1:i+1), 'g');
plot(0:dt:t, A(4, 1:i+1), 'y');
hold off