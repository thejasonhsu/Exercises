y=ones(11,11); %to generate 11 by 11 matrix to store the results of the function
RBCA=(0:0.08:0.8); %11 values of RBCA between 0 and 0.8
RBCB=(0:0.06:0.6); %11 values of RBCB between 0 and 0.6
for i=1:11, %loop instruction, repeat the same instructions 11 times
    for j=1:11, %loop instruction, repeat the same instructions 11 times
        y(i,j)=transfusion3(RBCA(i),RBCB(j)); %solve system using function and store in matrix y
    end %end of j loop
end %end of i loop
mesh(RBCA,RBCB,y) %3D plot
xlabel('RBCA') %3D labels
ylabel('RBCB');
zlabel('RBC content of transfusion pack');