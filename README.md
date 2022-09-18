# ACM 算法模板  



## 数论


### 素数


####  素数个数


素数定理：`pi(x) = x/ln(x)`
pi(x)表示小于x的素数的个数


```
// 基础筛法
// 素数个数度：

const int N = 1000000;
const int M = 300000;
bool is[N];
int prm[M];
int getprm() {
  int e = (int)(sqrt(0.0 + N) + 1), k = 0, i;
  memset(is, 1, sizeof(is));
  prm[k++] = 2;
  is[0] = is[1] = 0;
  for (i = 4; i < N; i += 2) is[i] = 0;
  for (i = 3; i < e; i += 2) {
    if (is[i]) {
      prm[k++] = i;
      for (int s = i + i, j = i * i; j < N; j += s) is[j] = 0;
    }
  }
  for (; i < N; i += 2)
    if (is[i]) prm[k++] = i;
  return k;
}
```


