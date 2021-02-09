%11
x1 = @(x) x^2;
x2 = @(x) x^3;
x3 = @(x) log(x);
x4 = @(x) 1/x;
subplot(2,2,01)
fplot(x1,[1,10])
subplot(2,2,2)
fplot(x2,[1,10])
subplot(2,2,3)
fplot(x3,[1,10])
subplot(2,2,4)
fplot(x4,[1,10])
