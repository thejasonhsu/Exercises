f = 1./x;
syms x;
diff(diff(f));
disp(diff(diff(f)));

K=2;
a=1;
b=5;

syms n;
E = solve(K*(b-a)^3-0.0001*(24*n^2),n);
disp('n for trap so that Et < 0.0001');
disp(ceil(E));