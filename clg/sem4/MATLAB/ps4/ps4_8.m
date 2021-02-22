%8
x = input("entert the temperature in Kelvin");
if (x-273 < 32 )
  disp("ICE")
elseif(x-273 < 212 && x-273 >=32)
  disp("WATER")
else
  disp("STEAM")
endif
  