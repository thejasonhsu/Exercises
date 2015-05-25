function eigen = eigen(a,b,c,d);
B=a+d;
C=a*d-b*c;
eigen1=(B+sqrt(B^2-4*C))/2;
eigen2=(B-sqrt(B^2-4*C))/2;
disp(eigen1);
disp(eigen2);
end
