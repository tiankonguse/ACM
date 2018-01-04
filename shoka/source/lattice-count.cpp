typedef long long LL;

LL count(LL n, LL a, LL b, LL m) {
    if (b == 0) { 
        return n * (a / m); 
    }
    if (a >= m) { 
        return n * (a / m) + count(n, a % m, b, m); 
    }
    if (b >= m) { 
        return (n - 1) * n / 2 * (b / m) + count(n, a, b % m, m); 
    }
    return count((a + b * n) / m, (a + b * n) % m, m, b);
}
