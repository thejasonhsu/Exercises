dt=0.1;
g=9.8;
a=0;
b=22;
m=(b-a)/dt;
v=zeros(1,m+1);
y=zeros(1,m+1);
v(1)=100;
y(1)=0;
t=a:dt:b;
for i=1:m;
    v(i+1)=v(i)-g*dt;
    y(i+1)=y(i)+v(i)*dt;
end
plot(t,y);
xlabel('time');
ylabel('vertical displacement');
grid;
figure
plot(t,v)
disp([t',v']);
disp([t',y']);
