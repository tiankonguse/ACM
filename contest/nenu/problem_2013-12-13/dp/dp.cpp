#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
#include<stdarg.h>
using namespace std;
#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif
/*
���

2113��,��138��ACM���ʴ�ѧ��������ƾ�����ʼ������.
ʱ����ͬ�ˣ�������Ҳ��ͬ�ˣ���Ȼ����Ҳ��ͬ�ˡ�
�����涨һ�������ٿ��Բμ�һ���ˣ�������Բμ�k�ˡ�
���ϵ�acmer���ˣ���ô������Ҫ�����أ�
�㲻�ù���ô���ˣ��Ѿ�˵��ʱ����ͬ�ˡ�
tiankonguse �������Ĵ�ѧ�󣬷���ѧԺ�պ���n��acm,��n��Сѧ��Сѧ����ǿ������
����tiankonguse�����ǳ���һ���ַ���ת�����͵������������ǣ���󽲽��屨��ʱ��tiankonguse��Ȼʹ�ÿ⺯�� sscanf ��ת����
sscanfʹ�÷������£�
������һ���ַ�����һ������������Ĵ���Ϳ��԰��ַ���ת��Ϊ���֡�

char str[100] = "1.230";
double number;
sscanf��str,"%lf",&number��;

����֮������ǽ����˴�֣�Ȼ�������ǵķ����պ��Ǵ�1�ֵ�n�֡�

tiankonguse ��ѧ��ѧ�ö��ݵĽӴ��󣬷��ֶ��ڷ������ڵ��������ǲ��ʺ���ӵġ�
������������ˣ���n��ѧ��ѧ���ж������ʺϵ���ӷ�ʽ�أ�

��������
�����ж������ݡ�
ÿ�������������� n��k.(1<=k,n<=1000 ������n��acmer,һ�������k����)


�������
����ж����ֺ��ʵ���ӷ�ʽ����ģ�� 1000000007

��������
1 1
10 1
10 2
245 21

�������
1
10
46
369305584


��ʾ
������ str[n][i]Ϊ ǰn��������i������ӣ���������۵�n�����Ƿ�����������


*/
int mod = 1000000007;
const int N = 1111;
int str[N][N];
int main() {
//    freopen("dp.in","r",stdin);
//    freopen("dp.out","w",stdout);
    int n,i,j,k;
    memset(str,0,sizeof(str));
    str[0][0] = 1;
    str[1][0] = 1;
    str[1][1] = 1;

    for(i=2; i<N; i++) {
        str[i][1] = i;
        str[i][0] = 1;
        for(j=2; j<=i; j++) {
            str[i][j] = (str[i-2][j-1] + str[i-1][j])%mod;
        }
    }
    int ans;
    while(~scanf("%d%d",&n,&k)) {
        if(k>n)k=n;
        ans = 0;
        for(i=1; i<=k; i++) {
            ans += str[n][i];
            ans %= mod;
        }
        printf("%d\n",ans);
    }


    return 0;
}
