%10
fn = @(x) (95000./(x.^2));
x2 = [10 12 14 16 18 20 22]
y2 = [950 640 460 340 250 180 140]
fplot(fn,[10,22])
hold on
plot(x2,y2,"--o")
hold off
legend('Theory','Experiment');
text(14,640, "Comparision between theory and exeriment");
title('Light Intensity as a Function of Distance');
xlabel('Distance(cm)');
ylabel('Intensity(lux)');
axis([8 24 0 1200]);
