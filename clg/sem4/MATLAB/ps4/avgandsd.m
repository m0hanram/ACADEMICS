%2
function [avg,sd] = avgandsd(x)
  sum = 0;
  sumation = 0;
  for i = x
    sum = sum + i;
  endfor
  avg = sum/length(x);
  for j = x
    sumation = sumation + (j - avg)^2;
  endfor
  sd = sqrt(sumation/length(x));
endfunction
