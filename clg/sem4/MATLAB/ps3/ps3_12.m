%12
fn = @(x) (((x+1)*(x-2)*(2*x - 0.25))-exp(x))
figure(1)
fplot(fn, [0,3])
figure(2)
fplot(fn, [-3,6]) 