def go(n):
	num = [0]*10;
	if (n == 0): return '10';
	if (n == 1): return '1';
	for i in range(9, 1, -1):
		while (n % i == 0):
			n /= i;
			num[i] += 1;
	if (n != 1): return '-1';
	ret = '';
	for i in range(2, 10):
		for j in range(num[i]):
			ret += (str)(i);
	return ret;
	
print go(input())
