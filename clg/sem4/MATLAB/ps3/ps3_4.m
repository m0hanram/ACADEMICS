%4
x1 = @(x) x^2;
x2 = @(x) x^3;
x3 = @(x) log(x);
x4 = @(x) 1/x;
fplot(x1,[1,10])
hold on
fplot(x2,[1,10])
hold on
fplot(x3,[1,10])
hold on
fplot(x4,[1,10])
hold off