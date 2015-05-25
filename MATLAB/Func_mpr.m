function mpr=midpoint(f,a,b,n);
h = (b-a)/n;
xpts = linspace(a+h/2,b-h/2,n-1);
y = 1./xpts;
mpr = h*sum(y);
end

%I couldn't figure out how to input f as a function, so y is the function
%itself