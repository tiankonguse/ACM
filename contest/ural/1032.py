n = input()
a = [0] + [-1] * n
b = [0]
s = 0
f = 0
for i in xrange(1, n + 1): 
	x = input()
	b.append(x)
	if (f != 0): continue
	s = (s + x) % n
	t = a[s]
	if (t != -1):
		print i - t
		for j in range(t + 1, i + 1):
			print b[j]
		f = 1
	a[s] = i
	
