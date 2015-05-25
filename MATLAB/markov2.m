clear all
P=[0 1/2 1/3 1 0; 1 0 1/3 0 1/3; 0 1/2 0 0 1/3; 0 0 0 0 1/3; 0 0 1/3 0 0];
i=1;
M=P^i;
while abs(M(1,1)-M(1,2))>10e-7;
    M=P^i;
    i=i+1;
end
disp(M);
[R,b]=sort(M(:,1),'descend');
disp(R);
disp(b);