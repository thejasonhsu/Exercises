function avgflips=ee150_broke(initP1,initP2,initP3,p,n) 
i=0;
for sequence=1:n
    flips=0;
    x(1)=initP1;
    x(2)=initP2;
    x(3)=initP3;
    while x(1)>0 && x(2)>0 && x(3)>0
        y(1)=rand;
        y(2)=rand;
        y(3)=rand;
        for j=1:3
            if y(j)<p
                y(j)=1;
            else 
                y(j)=0;
            end
        end
        
        roundtotal=sum(y);
        if roundtotal==1 || roundtotal ==2
            if roundtotal==1
                for j=1:3
                    if y(j)== 0
                        y(j)=-1;
                    else
                        y(j)=2;
                    end
                end
            else
                for j=1:3
                    if y(j)==0
                        y(j)=+2;
                    else
                        y(j)=-1;
                        
                    end
                end
            end
            for j=1:3
                x(j)=x(j)+y(j);
            end
        end
        flips=flips+1;
    end
    i=i+flips;
end
avgflips=i/n;
end