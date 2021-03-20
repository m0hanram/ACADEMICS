%1
syms x
a = (x^2-5)*(x^3-2*x+3);
diff(a)
b = sin(x)*cos(x);
diff(b)
c = abs(x);
diff(c)
d = x*abs(x);
diff(d)
e = (sqrt(x)+2*x)*(4*x^2-1);
diff(e)
f = (x^2+1)/(5*x-3);
diff(f)