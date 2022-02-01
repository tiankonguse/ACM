import math
l, r = map(float, raw_input().split())
ret = 0
if l >= r + r: ret = math.pi * r * r
elif 0.5 * math.sqrt(2.0) * l <= r: ret = l * l
else:
	l *= 0.5
	arc = math.acos(l / r)
	ret = l * r * math.sin(arc) + 0.5 * (0.5 * math.pi - 2.0 * arc) * r * r
	ret *= 4.0
	
print '%.3f' % ret
