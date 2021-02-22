%3
function y = fun3(x)
  y = 1:length(x);
  for i = 1:length(x),
    y(i) = -0.2*(x(i).^4) + (exp(-0.5*x(i))*(x(i).^3)) + (7*(x(i).^2));
  endfor
endfunction