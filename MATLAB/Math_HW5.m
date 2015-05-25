x = 1:0.001:5;
y = 1./x;
plot(x,y);

fun = @(x) 1./x;
I = quad(fun,1,5);
display(I);