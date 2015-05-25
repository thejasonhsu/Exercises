function simps = simpsons(f,a,b,n)
h=(b-a)/n;
x=linspace(a,b,n+1);
fx=feval(f,x);
simps=h/3*(fx(1)+4*sum(fx(2:2:n))+2*sum(fx(3:2:n-1))+fx(n+1));
end