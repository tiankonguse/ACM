const int INF = 1000000000;
int KM(int m, int n, vector < vector <int> > &mat) {
	int MAXN = max(m, n) + 5, p, q, ret = 0, i, j, k;
	vector <int> s, t, l1, l2, match1, match2;
	s = t = l1 = l2 = vector <int> (MAXN, 0);
	for (i = 0; i < m; i++) {
		l1[i] = -INF;
		for (j = 0; j < n; j++) {
			l1[i] = mat[i][j] > l1[i] ? mat[i][j] : l1[i];
		}
	}
	for (i = 0; i < n; l2[i++] = 0);
	match1 = match2 = vector <int> (MAXN, -1);
	for (i = 0; i < m; i++) {
		fill(t.begin(), t.end(), -1);
		for (s[p = q = 0] = i; p <= q && match1[i] < 0; p++) {
			k = s[p];
			for (j = 0; j < n && match1[i] < 0; j++) {
				if (l1[k] + l2[j] == mat[k][j] && t[j] < 0) {
					s[++q] = match2[j];
					t[j] = k;
					if (s[q] < 0) {
						for (p = j; p >= 0; j = p) {
							match2[j] = k = t[j];
							p = match1[k]; match1[k] = j;
						}
					}
				}
			}
		}
		if (match1[i] < 0) {
			i--;
			p = INF;
			for (k = 0; k <= q; k++) {
				for (j = 0; j < n; j++) {
					if (t[j] < 0 && l1[s[k]] + l2[j] - mat[s[k]][j] < p) {
						p = l1[s[k]] + l2[j] - mat[s[k]][j];
					}
				}
			}
			for (j = 0; j < n; j++) { l2[j] += t[j] < 0 ? 0 : p; }
			for (k = 0; k <= q; k++) { l1[s[k]] -= p; }
		}
	}
	for (i = 0; i < m; i++) ret += mat[i][match1[i]];
	return ret;
}

