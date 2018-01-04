typedef long long LL;

LL pollard_rho(LL n, LL seed) {
    LL x, y, head = 1, tail = 2;
    x = y = rand() % (n - 1) + 1;
    while (true) {
        x = multiply_mod(x, x, n);
        x = add_mod(x, seed, n);
        if (x == y) {
            return n;
        }
        LL d = gcd(abs(x - y), n);
        if (1 < d && d < n) {
            return d;
        }
        head ++;
        if (head == tail) {
            y = x;
            tail <<= 1;
        }
    }
}

vector <LL> divisors;

void factorize(LL n) {
    if (n > 1) {
        if (is_prime(n)) {
            divisors.push_back(n);
        } else {
            LL d = n;
            while (d >= n) {
                d = pollard_rho(n, rand() % (n - 1) + 1);
            }
            factorize(n / d);
            factorize(d);
        }
    }
}
