a = sin(linspace(-pi,pi, 100));
b = cos(linspace(-pi,pi, 100));
res = hypot(a, b);
a1 = b + 0.337 *a;
a2 = max(b, 0.918 * (b + bitsra(a,1)));
a3 = (abs(a) + abs(b))/1.25;
%a3 = b + 0.428 * a * a / b;


figure(1)
plot(res, 'g');
title('Combine Plots')
grid on

hold on
plot(a1)

hold on
plot(a2)

hold on
plot(a3)



legend('hpothenuse','a1','a2','a3')