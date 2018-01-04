void rebuild(const Point &a, const Point &b) {
    points[n] = points[0];
    int m = 0;
    for (int i = 0; i < n; ++ i) {
        double s_1 = det(b - a, points[i] - a);
        double s_2 = det(b - a, points[i + 1] - a);
        if (signum(s_1) * signum(s_2) < 0) {
            newPoints[m ++] = (points[i + 1] * s_2 - points[i] * s_1) / (s_2 - s_1);
        }
        if (signum(det(b - a, points[i + 1] - a)) >= 0) {
            newPoints[m ++] = points[i + 1];
        }
    }
    n = m;
    copy(newPoints, newPoints + n, points);
}
