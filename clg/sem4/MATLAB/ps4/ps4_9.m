%9
x = input("enter the number");
pri = 0;
for i = 2:(x-1),
    if (i != x)
      if (rem(x,i) == 0)
        pri = 1;
      endif
    endif
endfor
if (pri == 0 && x > 1)
  disp("prime")
elseif(pri == 1 && x > 1)
  disp("not prime")
else
  disp("enter nos greater than 1")
endif
  