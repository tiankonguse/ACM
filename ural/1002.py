mp = '22233344115566070778889990';
def match(pos, s, num):
	if (len(s) > pos + 1): return False;
	for i in range(len(s)): 
		if (mp[(ord)(s[i])-97] != num[pos-len(s)+i+1]): return False;
	return True;
	
while (True):
	num = raw_input(); 
	if (num == '-1'): break;
	s = [];
	f = [101010] * 101;
	f[0] = 0;
	g = [-1] * 101;
	n = input();
	for i in range(n): s.append(raw_input());
	for i in range(len(num)):
		for j in range(n):
			if (match(i, s[j], num)):
				if (f[i-len(s[j])+1] + 1 < f[i+1]):
					f[i+1] = f[i-len(s[j])+1] + 1;
					g[i+1] = j;
	if (f[i+1] == 101010):
		print 'No solution.'
	else:
		ret = [];
		pos = len(num);
		while (pos > 0):
			ret.append(s[g[pos]]);
			pos -= len(s[g[pos]]);
		
		for i in range(f[len(num)] - 1, -1, -1):
			print ret[i],
		print 
