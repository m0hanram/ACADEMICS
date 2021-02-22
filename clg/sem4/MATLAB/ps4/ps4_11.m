%11
for i = 1:4,
  strin = '';
  for j = 1:i,
    strin = strcat(strin,"*");
  endfor
  disp(strin)
endfor