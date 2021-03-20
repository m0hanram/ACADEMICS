%7
syms y(x);
syms x;

a = diff(y,x) == 9.8-(0.196*y);
cond1=y(0)==48;
vpa(dsolve(a,cond1))

b = (x*diff(y,x))+(2*y)== (x^2 - x + 1);
cond2=y(1)==(1/2);
dsolve(b,cond2)

c = (x*diff(y,x))-(2*y)==((x^5)*sin(2*x)-(x^3)+(4*(x^4)));
cond3=y(pi)==((3/2)*(pi^4));
dsolve(c,cond3)

d=2*(diff(y,x))-y == 4*(sin(3*x));
cond4=y(0)==1;
dsolve(d,cond4)

e=diff(y,x,2)-diff(y,x)-(3*y)==0;
dsolve(e,y(0)==0,subs(diff(y,x),x,0)==1);

f=diff(y,x,2)+(4i+1)*diff(y,x)+y==0;
dsolve(f,y(0)==0,subs(diff(y,x),x,0)==0)

g=diff(y,x,2)+10*y==0;
dsolve(g,y(0)==pi,subs(diff(y,x),x,0)==2)

h=diff(y,x,2)==4-sin(x)+y-2*diff(y,x);
dsolve(h,y(0)==1,subs(diff(y,x),x,2)==2)

%i=diff(y,x,3)==y-x*y+4*diff(y,x,2);
%dsolve(i,y(2)==1,subs(diff(y,x),x,2)==2,subs(diff(y,x,2),x,2)==3,)
