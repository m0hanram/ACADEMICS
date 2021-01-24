% q1 
% a
q1a = ((14.8^2+6.5^2)/3.8^2)+(55/(sqrt(2)+14)) 

% b
q1b = ((-3.5)^3)+(exp(6)/log(524))+(206^(1/3))

% q2 
% a 
q2a = ((16.5)^2*(8.4 - sqrt(70)))/((4.3)^2-17.3) 

%b
q2b = (((5.2)^3 - (6.4)^2 + 3)/((1.6)^8 - 2)) + ((13.3)/5)^(1.5)

%q3
%a
q3a = 15*((sqrt(10) + (3.7)^2)/(log10(1365) + 1.9))

%b
q3b = (((2.5)^3*(16 - (216/22))) / ((1.7)^4 + 14)) + 2050^(1/4)

%q4
%a
q4a = ((2.3)^2*(1.7))/sqrt((1 - (0.8)^2)^2+(2 - sqrt(0.87))^2)

%b
q4b = 2.34 + (1/2)*(2.7)*((5.9)^2 - (2.4)^2) + (9.8)*log(51)

%q5
%a
q5a = (sin(7*pi/9)/(cos(5*pi/7))^2) + (1/7*tan(5*pi/12))

%b
q5b = tand(64)/(cosd(14)^2) - ((3*sind(80))/((0.9)^(1/3))) + (cosd(55)/sind(11)) 

%q6
%a
x = 2.34;
q6a = (2*x^4) - (6*x^3) + (14.8*x^2) + 9.1

%b
q6b = exp(2*x)/sqrt(14 + x^2 - x)
clear x

%q7
%a
t = 6.8;
q7a = log(abs(t^2 - t^3))

%b
q7b = (75*cos(0.8*t - 3))/(2*t)
clear t

%q8
%a
x = 8.3;
y = 2.4;
q8a = x^2 + y^2 - ((x^2)/(y^2))

%b
q8b = sqrt(x*y) - sqrt(x+y) + ((x-y)/(x-2*y))^2 - sqrt(x/y)
clear x y

%q9
%a
a = 13;
b = 4.2;
c = (4*b)/a;
d =  (a*b*c)/(a+b+c);
q9a = a*b/(c+d) + (d*a)/(c*b) - (a-b^2)*(c+d)

%b
q9b = sqrt(a^2 + b^2)/(d-c) + log(abs(b-a+c-d))

%q10
f = @(x,a) cos(a*x).^2;
q10 = integral(@(x) f(x,0.5),pi/9,3*pi/5)

%q11
%a
a=9;
b=3;
q11a = 2*pi*sqrt((1/2)*(a^2+b^2))
clear a b

%b
a = 20/(pi*sqrt(10))
clear a 

%q12
%a
x = pi/9;
lhs = sin(4*x)
rhs = (4*sin(x)*cos(x)) - (8*(sin(x)^3)*cos(x))
if(lhs == rhs)
    printf("equal\n")
else
    printf("not equal\n")
endif

%b
lhs1 = cos(2*x)
rhs1 = (1-tan(x)^2)/(1+tan(x)^2)
if(lhs1 == rhs1)
    printf("equal\n")
else
    printf("not equal\n")
endif
clear x

%q13
a = 16;
c = 50;
b = sqrt(c^2-a^2)
alpha = acosd(b/c) 
clear a c

%q14
x=8;
y=3;
z=-10;
A=2;
B=23;
C=13;
D=-24;
d= abs(A*x + B*y + C*z + D)/sqrt(A^2+B^2+C^2)

