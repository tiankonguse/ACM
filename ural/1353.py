dp = [[-1 for i in range(82)] for j in range(10)]
num = [0]*10
def dfs(pos, s, flag):
	if (pos == -1): return s == 0;
	if (flag == 0 and dp[pos][s] != -1): return dp[pos][s];
	end = num[pos] if flag == 1 else 9;
	ret = sum(dfs(pos - 1, s - i, flag & (i == end)) for i in range(0, min(end, s) + 1))
	if (flag == 0): dp[pos][s] = ret;
	return ret;

s = input();
num[9] = 1;
print dfs(9, s, 1);
