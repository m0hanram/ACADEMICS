%1
q1 = [3 (4*2.55) (68/16) 45 110^(1/3) cosd(25) 0.05]

%2
q2 = [(32/(3.2)^2);sind(35)^2;6.1;log((29)^2);0.00552;log((29)^2);133]

%3
q3 = linspace(81,12,9)

%4
q4 = linspace(-21,12,15)'

%5
q5 = zeros(1,9);
q5(9) = 7.5

%6
vecA = linspace(49,10,14)
vecB = [vecA(1:4) vecA(11:14)]

%7
A = [linspace(0,30,7);linspace(600,0,7);linspace(0,5,7)]

%8
a = [7 2 -3 1 0];
b = [-3 10 0 7 -2];
c = [1 0 4 -6 5];
%a
q8a = [a;b;c]
%b
q8b = [a' b' c']

%9 
%a
q9a = [a(1:3);b(1:3);c(1:3)]
%b
q9b = [a(3:5)' b(3:5)' c(3:5)']

%10
A = [linspace(2,17,6);linspace(3,18,6);linspace(4,19,6);linspace(5,20,6);linspace(6,21,6)];
B = [linspace(5,30,6);linspace(30,55,6);linspace(55,80,6)];
v = [linspace(99,91,9)];
A(1,3:6) = B(1,1:4);
A(3,3:6) = B(2,1:4);
A(4,3:6) = v(5:8);
A(5,3:6) = B(3,2:5)