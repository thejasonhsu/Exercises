clear all
format long
P=[0 1/2 1/3 1 0; 1 0 1/3 0 1/3; 0 1/2 0 0 1/3; 0 0 0 0 1/3; 0 0 1/3 0 0];
p0=[0; 0; 1; 0; 0];
p1=P*p0;
for i=1:100;
    M=P^i;
end
disp(M);
[R,b]=sort(M(:,1),'descend');
disp(R);
disp(b);

clear all
format short
P=[0 1/2 1/3 1 0; 1 0 1/3 0 1/3; 0 1/2 0 0 1/3; 0 0 0 0 1/3; 0 0 1/3 0 0];
p0=[0; 0; 1; 0; 0];
p1=P*p0;
for i=1:100;
    M=P^i;
end
disp(M);
[R,b]=sort(M(:,1),'descend');
disp(R);
disp(b);