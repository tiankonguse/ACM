n, k = input(), input()
u, v = 0, k - 1
for i in range(2, n + 1): u, v = v, (u + v) * (k - 1)
print u + v
