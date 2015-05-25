i=1;
p=0.1:0.1:0.9;
for i=1:9
    points(1,i)=ee150_broke(3,3,3,p(1,i),100000);
end
plot(p,points(1,:))