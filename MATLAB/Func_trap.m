function trap = trapezoid(f,a,b,n)
h = (b-a)/n;
trap = 0;
for z = 1:n-1
    x=a+h*z;
    trap = trap+feval(f,x);
end
trap = h*(feval(f,a)+feval(f,b))/2+h*trap;