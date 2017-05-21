a = [0] * 100000
b = [0] * 100000
a[0] = 0
a[1] = 1
b[1] = 1
for i in range(2, 100000):
	a[i] = a[i // 2] + a[i // 2 + 1] if i & 1 else a[i // 2]
	b[i] = max(b[i - 1], a[i])
while (True):
	n = input()
	if (n == 0): break
	print b[n]
