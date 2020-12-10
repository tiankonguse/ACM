//Adaptive Simpson's Rule integral
double F(double x)
{
    return sqrt(1 + 4 * a * a * x * x);
}
double simpson(double a , double b)
{
    double c = (a + b) * 0.5;
    return (F(a) + 4 * F(c) + F(b)) * (b - a) / 6;
}
double asr(double a , double b , double eps , double A)
{
    double c = (a + b) * 0.5;
    double L = simpson(a , c) , R = simpson(c , b);
    if (fabs(L + R - A) <= 15 * eps)
        return L + R + (L + R - A) / 15;
    return asr(a , c , eps / 2 , L) + asr(c , b , eps / 2 , R);
}
double cal()
{
    a = 4 * m / w / w;
    return n * 2 * asr(0 , w / 2 , 1e-5 , simpson(0 , w / 2));
}
