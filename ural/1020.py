import math
n, r = map(float, raw_input().split());
x0, y0 = map(float, raw_input().split());
x1, y1 = x0, y0
ret = math.pi * 2.0 * r;
for i in range(1, (int)(n)):
	x2, y2 = map(float, raw_input().split());
	ret += math.hypot(x1 - x2, y1 - y2);
	x1, y1 = x2, y2
ret += math.hypot(x0 - x1, y0 - y1)
print '%.2f' % ret
