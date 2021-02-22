%12
for i = 1:5,
  strin = '';
  for j = 1:i,
    strin = strcat(strin,"*");
  endfor
  if(rem(i,2) != 0)
      disp(strin)
  endif
endfor
for k = 3:-1:1,
  strin = '';
  for l = 1:k,
    strin = strcat(strin,"*");
  endfor
  if(rem(k,2) != 0)
      disp(strin)
  endif
endfor