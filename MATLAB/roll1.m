function Y=roll1(n,k)
a=factorial(n);
b=factorial(k);
c=factorial(n-k);
C=a/(b*c);
Y=C*(1/3)^k*(2/3)^(n-k);