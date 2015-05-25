clear all
P=[0 1/2 1/3 1 0; 1 0 1/3 0 1/3; 0 1/2 0 0 1/3; 0 0 0 0 1/3; 0 0 1/3 0 0];
i=1;
M=P^i;
while sum(abs(M(:,1)-M(:,2))>10e-7)~= 0;
    M=P^i;
    i=i+1;
end
disp(M);
[R,b]=sort(M(:,1),'descend');
disp(R);

for k=1:length(b)
    if b(k)==1;
        disp('A');
    elseif b(k)==2;
        disp('B');
    elseif b(k)==3;
        disp('C');
    elseif b(k)==4;
        disp('D');
    elseif b(k)==5;
        disp('E');
    end
end