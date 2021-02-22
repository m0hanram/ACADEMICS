%14
len = input("enter the number : ");
for i = 1 : 100
  if(fib(i) > len)
    break;  
  endif
  printf("%d, ", fib(i));
endfor
