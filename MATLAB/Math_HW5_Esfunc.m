f = 1./x;
syms x;
Z=diff(diff(diff(diff(f))));
disp(Z);

K=24;
a=1;
b=5;

syms n;
E = solve(K*(b-a)^5-0.0001*(180*n^4),n);
disp('n for simps so that Es < 0.0001');
disp(ceil(E));