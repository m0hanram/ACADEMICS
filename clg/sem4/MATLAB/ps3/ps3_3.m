%3
X = -2:0.01:4;
fn = @(x) ((3.5)^(-0.5*x))*cos(6*x)
fplot(fn,[-2,4])