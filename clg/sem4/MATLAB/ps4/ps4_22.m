%22
sum = 0;
j = 0;
for i = 1:2:9999,
  if(rem(j, 2) == 0)
    sum = sum + (i*i);
  else
    sum = sum - (i*i);
  endif
  j = j + 1;
endfor
disp(["The sum of the series is : ",num2str(sum)]);