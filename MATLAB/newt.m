n=input('Cube root of n ');
x=input('Initial Guess ');
i=0;
r1=1e-10;
r2=1;
f(x)=n^(1/3)-x;
f1(x)=1/3*x^(-2/3);
while r2>r1 &&(i<10);
    xold=x;
    x=x-f(x)/f1(x);
    i=i+1;
    disp([x f(x)])
    r2=abs((x-x0)/x);
end
if r2<=r1
    disp('Zero found at')
    disp(x)
else
    disp('Zero not found')
end