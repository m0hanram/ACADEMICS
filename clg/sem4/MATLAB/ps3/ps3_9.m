%9
x = linspace(-2,4);
fn = 3*(x.^3) - 26*x + 10;
d1 = diff(fn);
d2 = diff(d1);
coordinates1 = x(1:end-1);
coordinates2 = x(1:end-2);
x_co = [x coordinates1 coordinates2]
y_co = [fn d1 d2]
line(x_co, y_co)