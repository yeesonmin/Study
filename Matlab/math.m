x = linspace(-5,5,1000)
y = (3*x.^5-x.^2+1)./(x.^2-2)
plot(x,y)
axis([-4 4 -50 50])