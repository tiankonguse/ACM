#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>
#include	<time.h>
#include	<math.h>

int *primarr, *v;
int q = 1, p = 1;

//π(n)
int pi(int n, int primarr[], int len)
{
    int i = 0, mark = 0;
    for (i = len - 1; i > 0; i--) {
        if (primarr[i] < n) {
            mark = 1;
            break;
        }
    }
    if (mark)
    return i + 1;
    return 0;
}

//Φ(x,a)
int phi(int x, int a, int m)
{
    if (a == m)
    return (x / q) * p + v[x % q];
    if (x < primarr[a - 1])
    return 1;
    return phi(x, a - 1, m) - phi(x / primarr[a - 1], a - 1, m);
}

int prime(int n)
{
    char *mark;
    int mark_len;
    int count = 0;
    int i, j, m = 7;
    int sum = 0, s = 0;
    int len, len2, len3;

    mark_len = (n < 10000) ? 10002 : ((int)exp(2.0 / 3 * log(n)) + 1);

    //筛选n^(2/3)或n内的素数
    mark = (char *)malloc(sizeof(char) * mark_len);
    memset(mark, 0, sizeof(char) * mark_len);
    for (i = 2; i < (int)sqrt(mark_len); i++) {
        if (mark[i])
        continue;
        for (j = i + i; j < mark_len; j += i)
        mark[j] = 1;
    }
    mark[0] = mark[1] = 1;

    //统计素数数目
    for (i = 0; i < mark_len; i++)
    if (!mark[i])
    count++;

    //保存素数
    primarr = (int *)malloc(sizeof(int) * count);
    j = 0;
    for (i = 0; i < mark_len; i++)
    if (!mark[i])
    primarr[j++] = i;

    if (n < 10000)
    return pi(n, primarr, count);

    //n^(1/3)内的素数数目
    len = pi((int)exp(1.0 / 3 * log(n)), primarr, count);
    //n^(1/2)内的素数数目
    len2 = pi((int)sqrt(n), primarr, count);
    //n^（2/3)内的素数数目
    len3 = pi(mark_len - 1, primarr, count);

    //乘积个数
    j = mark_len - 2;
    for (i = (int)exp(1.0 / 3 * log(n)); i <= (int)sqrt(n); i++) {
        if (!mark[i]) {
            while (i * j > n) {
                if (!mark[j])
                s++;
                j--;
            }
            sum += s;
        }
    }
free(mark);
sum = (len2 - len) * len3 - sum;
sum += (len * (len - 1) - len2 * (len2 - 1)) / 2;

    //欧拉函数
    if (m > len)
    m = len;
    for (i = 0; i < m; i++) {
        q *= primarr[i];
        p *= primarr[i] - 1;
    }
    v = (int *)malloc(sizeof(int) * q);
    for (i = 0; i < q; i++)
    v[i] = i;
    for (i = 0; i < m; i++)
    for (j = q - 1; j >= 0; j--)
    v[j] -= v[j / primarr[i]];

    sum = phi(n, len, m) - sum + len - 1;
    free(primarr);
    free(v);
    return sum;
}

int main()
{
    int n;
    int count;
    clock_t start, end;
    scanf("%d", &n);

    start = clock();
    count = prime(n);
    end = clock() - start;
    printf
    ("[%d]内的素数个数为%d，计算用时：%d毫秒\n",
     n, count, (int)end / 1000);
    getchar();
    return 0;
}
