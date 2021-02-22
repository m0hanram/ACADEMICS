%13
x = input("Enter the number");
mult = 1;
for i = 1:x,
  mult = mult*i;
endfor
printf("The factorial of the number entered is : %d", mult)