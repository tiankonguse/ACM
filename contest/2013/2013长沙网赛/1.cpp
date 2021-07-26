#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <stack>
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define E exp(double(1))
#define maxn 110000
using namespace std;
typedef long long  LL;
const int N=80010;
const int M=80010;
bool is[N];
int prm[M];
int num;
int twoAdd[N];
int twoMul[N];
int ans[N];

const int MOD = 1000000007;
int getprm() {
    int e = (int)(sqrt(0.0 + N) + 1),k=0,i;
    memset(is, 1, sizeof(is));
    prm[k++] = 2;
    is[0] = is[1] = 0;
    for (i = 4; i < N; i += 2) is[i] = 0;
    for(i=3; i<e; i+=2) {
        if(is[i]) {
            prm[k++]=i;
            for(int s=i+i,j=i*i; j<N; j+=s)is[j]=0;
        }
    }
    for (; i < N; i += 2)
        if (is[i])prm[k++] = i;
    return k;
}

int main() {
    int p,k,j,i;
    memset(ans,0,sizeof(ans));
    num = getprm();
    int tmp1,tmp2;
//     printf("%d\n",num);
//for(i=0;i<10;i++){
//    printf("%d %d\n",i,prm[i]);
//}
//    freopen("out1.txt","w",stdout);
    num = 10;
    for(k=0; k<num; k++) {
        printf("%d\n",k);
        ans[prm[k]]++;

        for(i=k; i<num; i++) {

            tmp1 = prm[k] + prm[i];
            if(tmp1 > 80001) {
                break;
            }
            if(tmp1 < 80001) {
                ans[tmp1]++;
                if(tmp1 == 6) {
                    printf("6  %d  + %d\n",prm[k] ,prm[i]);
                }
            }
            tmp1 = prm[k] * prm[i];

            if(tmp1 < 80001) {
                ans[tmp1]++;
                if(tmp1 == 6) {
                    printf("6  %d  * %d\n",prm[k] ,prm[i]);
                }
            }
            for(j=i; j<num; j++) {
                tmp1= prm[i] + prm[j] + prm[k];
                if(tmp1 > 80001) {
                    break;
                }
                if(tmp1 < 80001) {
                    ans[tmp1]++;
                    if(tmp1 == 6) {
                        printf("6  %d  + %d+ %d\n",prm[k] ,prm[i],prm[j]);
                    }
                }
                tmp2 = prm[i] * prm[j];
                if(tmp2 < 80001) {
                    tmp1=  tmp2* prm[k];
                    if(tmp1 < 80001) {
                        ans[tmp1]++;
                        if(tmp1 == 6) {
                            printf("6  %d  * %d* %d",prm[k] ,prm[i],prm[j]);
                        }
                    }
                }


                if(k != i && i != j) {
                    tmp1= prm[k] + prm[i] * prm[j];
                    if(tmp1 < 80001) {
                        ans[tmp1]++;
                        if(tmp1 == 6) {
                            printf("6  1 k %d  i %d   j %d\n",prm[k] ,prm[i],prm[j]);
                        }
                    }
                    tmp1= prm[i] + prm[k] * prm[j];
                    if(tmp1 < 80001) {
                        if(tmp1 == 6) {
                            printf("6  2 k %d  i %d   j %d\n",prm[k] ,prm[i],prm[j]);
                        }
                        ans[tmp1]++;
                    }
                    tmp1= prm[j] + prm[i] * prm[k];
                    if(tmp1 < 80001) {
                        if(tmp1 == 6) {
                            printf("6  3 k %d  i %d   j %d\n",prm[k] ,prm[i],prm[j]);
                        }
                        ans[tmp1]++;
                    }
                } else if(k == i && k == j) {
                    tmp1= prm[j] + prm[i] * prm[k];
                    if(tmp1 < 80001) {
                        if(tmp1 == 6) {
                            printf("6  4 k %d  i %d   j %d\n",prm[k] ,prm[i],prm[j]);
                        }
                        ans[tmp1]++;
                    }
                } else if(k == i && k != j) {
                    tmp1= prm[k] + prm[i] * prm[j];
                    if(tmp1 < 80001) {
                        if(tmp1 == 6) {
                            printf("6  5 k %d  i %d   j %d\n",prm[k] ,prm[i],prm[j]);
                        }
                        ans[tmp1]++;
                    }
                    tmp1= prm[j] + prm[i] * prm[k];
                    if(tmp1 < 80001) {
                        if(tmp1 == 6) {
                            printf("6  6 k %d  i %d   j %d\n",prm[k] ,prm[i],prm[j]);
                        }
                        ans[tmp1]++;
                    }
                } else if(k != i && k == j) {
                    tmp1= prm[k] + prm[i] * prm[j];

                    if(tmp1 < 80001) {
                        if(tmp1 == 6) {
                            printf("6  7 k %d  i %d   j %d\n",prm[k] ,prm[i],prm[j]);
                        }
                        ans[tmp1]++;
                    }
                    tmp1= prm[i] + prm[j] * prm[k];

                    if(tmp1 <80001) {
                        ans[tmp1]++;
                        if(tmp1 == 6) {
                            printf("6  8 k %d  i %d   j %d\n",prm[k] ,prm[i],prm[j]);
                        }
                    }
                }

            }

        }

    }
    for(k=2; k<=10; k++) {
        printf("%d %d\n",k,ans[k]);
    }

    return 0;
}
