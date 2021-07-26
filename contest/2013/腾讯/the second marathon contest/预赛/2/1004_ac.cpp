#include<stdio.h>
#include<math.h>
#include<string.h>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;
typedef __int64 lld;

const int MAX=110000*2;
int str[MAX];//原字符串
int sb[MAX];
int p[MAX];//表示以i为中心的回文半径，
/*p[i]-1刚好是原字符串以第i个为中心的回文串长度。
画画图就知道了，因为两端配匹的肯定是字符g
*/
/*
Mancher主算法。
学习地址：http://blog.csdn.net/ggggiqnypgjg/article/details/6645824
功能：求出以i为中心的回文半径p[i];
参数：传入构造好的字符串长度
特殊说明：因为前面加了一个无效字符，所以下标从1开始。
例题：http://acm.hdu.edu.cn/showproblem.php?pid=3068
http://poj.org/problem?id=3974
http://acmpj.zstu.edu.cn/JudgeOnline/showproblem?problem_id=3780
http://acmpj.zstu.edu.cn/JudgeOnline/showproblem?problem_id=3769
http://acm.hust.edu.cn:8080/judge/contest/view.action?cid=12581#problem/A
http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=3661
http://acm.hdu.edu.cn/showproblem.php?pid=3948

*/
bool dig(char x){return x>='0'&&x<='9';}
int getval()
{
    int ret=0,sign=1;
    char c;
    while(!dig(c=getchar())&&c!='-');
    if(c=='-')sign=-1;
    else ret=c-'0';
    while(dig(c=getchar()))ret=ret*10+c-'0';
    return ret*sign;
}
void Manacher(int n)
{
    int i;
    int mx=0;//记录前面回文串最长影响到的地方。不一定是最长回文串造成的。
    int id;//最长影响串的ID;
    p[0]=0;
    for(i=1;i<n;i++)
    {
        p[i]=1;//至少是1
        if(mx>i)//i受到影响即，id+p[id]-1>=i;
        {
            p[i]=p[2*id-i];//2*id-i是i关于id的对称点相当于是id-(i-id);
            if(mx-i<p[i])p[i]=mx-i;
            //由于对称点的回文半径可能超过mx-i,因为mx后面的还没有配过
            //所以要取小的。等等继续配
        }

        //向两端配匹
        while(str[i-p[i]]==str[i+p[i]])
        {
            if(str[i+p[i]]==1)
            {
                p[i]++;
            }
            else
            {
                int a=i-p[i];
                int b=i+p[i];

                if(a+2<=b-2&&str[a]<=str[a+2]&&str[b-2]>=str[b])
                {
                    p[i]++;
                    continue;
                }
                else if(a==b)
                {
                    p[i]++;
                    continue;
                }
                else if(a+2>b-2)
                {
                    p[i]++;
                    continue;
                }


                break;
            }
        }

        if(i+p[i]>mx)
        {
            mx=i+p[i];
            id=i;
        }
    }
}

/*
功能：构造字符串，在每一个字符前插入一个，g,一般用'#'
第一个字符前面再插入,first,一般用'$'
最后再插入g字符
总之不是在输入中出现的字符就行了。
比如abb,构造成$#a#b#b#
参数：<first,第一个字符>，<g,一般字符>

返回值：构造好的字符串长度
*/
int pre(int first,int g,int m)
{
    int i,n=0;
    memcpy(sb,str,sizeof(int)*(m+2));
    str[0]=first;
    n++;
    for(i=0;i<m;i++)
    {
        str[n++]=g;
        str[n++]=sb[i];
    }

    str[n++]=g;
    str[n]=3;
    return n;
}
int main()
{
    int n;
    int i;
    int CS=1;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            //scanf("%d",&str[i]);
            str[i]=getval();
        }
        n=pre(0,1,n);
        Manacher(n);
        int ans=0;

        for(i=1;i<n;i++)
        {
            if(p[i]>ans)ans=p[i];
        }

        printf("%d\n",ans-1);
    }
    return 0;
}
