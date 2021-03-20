%5
syms x;
a = sin(2*x)*cos(x);
int(a)
b = 1/((x^2) + 5*x + 6);
int(b)
c = sqrt(9 - 4*(x^2));
int(c)
d = log(tan(x));
vpa(int(d,[0 (pi/2)]))
e = 1/(1 + sqrt(cot(x)));
vpa(int(e, [(pi/6) (pi/3)]))
f = sin(x)*(cos(x)^4);
vpa(int(f, [-1 1]))
g = @(x, y) 12.*(x^2).*(y^3);
integral2(g,-1,0,1,2)
h = @(x,y) x.*exp(x*y);
integral2(h,1,3,1,2)
i = @(x,y,z) 8.*x.*y.*z;
integral3(i,0,1,0,2,0,3)
j = @(x,y,z) x+y;
zmax = @(x) 4 - x^2;
integral3(j,0,zmax,0,2,0,1,'Method','tiled')
