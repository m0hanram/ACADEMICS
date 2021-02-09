%8
x = linspace(-2,4);
fn = 3*(x.^3) - 26*x + 10;
d1 = diff(fn);
d2 = diff(d1);
coordinates1 = x(1:end-1);
coordinates2 = x(1:end-2);
plot(x,fn)
hold on
plot(coordinates1,d1)
hold on
plot(coordinates2,d2)
hold off