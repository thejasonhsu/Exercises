function [probability] = roll2(n,k)
kconfirmed = 0;
for i=0:100000;
    reds=0;
    r=randi(3,n,1);
    for i=1:n;
        if r(i)==1
            reds=reds+1;
        end
    end
    if reds==k;
        kconfirmed=kconfirmed+1; 
    end
end
probability=kconfirmed/100000;
end