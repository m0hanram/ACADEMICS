%6
syms y(x);
a = diff(y,x) == exp(3*x) + sin(x);
dsolve(a)
b = diff(y,x,2) == 2 + x;
dsolve(b)
c = diff(y,x,10) == 0;
dsolve(c)
d = diff(y,x,3) == x^2;
dsolve(d)
e = diff(y,x) + cos(x)*y == sin(x)*cos(x);
dsolve(e)