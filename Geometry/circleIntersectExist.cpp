bool check(int n, double x[], double y[], double r[]) {
	const double eps = 1e-6;
	const double INF = 1e8;
	double L = -INF, R = INF, U, D;
	for (int i = 0; i < n; i++) {
		L = max(L, x[i] - r[i]);
		R = min(R, x[i] + r[i]);
	}
	if (L + eps < R) {
		for (int o = 0; o < 60; o++) {
			double mid = (L + R) / 2;
			D = -INF; U = INF;
			int j, k;
			for (int i = 0; i < n; i++) {
				double d = sqrt(r[i] * r[i] - (x[i] - mid) * (x[i] - mid));
				if (y[i] + d < U) {
					U = y[i] + d;
					j = i;
				}
				if (y[i] - d > D) {
					D = y[i] - d;
					k = i;
				}
			}
			if (D + eps < U) return 1;
			if ((x[j] - x[k]) * (x[j] - x[k]) + (y[j] - y[k]) * (y[j] - y[k]) + eps > (r[j] + r[k]) * (r[j] + r[k])) return 0;
			if (x[j] > x[k]) swap(j, k);
			double curx = x[j] + r[j] / (r[j] + r[k]) * (x[k] - x[j]);
			if (curx < mid) {
				R = mid;
			} else {
				L = mid;
			}
		}
		return 0;
	} else {
		return 0;
	}
}
