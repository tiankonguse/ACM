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
2113年,tiankonguse 来到了他的大学。老师交给他一个任务。
我们知道每个学生都有学分的，这个任务就是要对几张名单上的学生按学分从大到小排序。
然后按顺序发奖学金，但是看到奖学金，大家惊呆了。
原来每张名单上有n个人,排序后的第一个人得到n元奖学金，第二个人得到n-1元奖学金，最后一个人得到1元奖学金。
当然，排序前在名单前面的学生当然不希望和在他后面的和他相同学分的同学的奖学金比他多啦。
看到成绩单，tiankonguse 惊呆了，有一个学生的英语听力考试考了 59.50 分，得到这0.5学分真不容易呀。


输入描述
输入由若干张张名单组成，直到文件结尾。
每张名单的第一行是一个n(1<=n<=1000)，代表学生的个数。
接下来n行，每一行一个字符串name(代表名字，由小写字母组成,最多20个字符)和一个数字score(代表学分,0<=score<= 10000)。

输出描述
对于每一个名单，输出n行，代表排序后的名单。
每一行有名字和学分组成。名字和学分原样输出,名字和学分之间一个空格。

样例输入

5
aaa 32
bbb 12
ccc 32
ddd 14
eee 32



样例输出
aaa 32
ccc 32
eee 32
ddd 14
bbb 12




*/
const int N = 1111;
struct T{
	char name[30];
	char _score[100];
	double score;
	bool operator<(T const &o)const{
		return this->score > o.score;
	}
}str[N];

int main() {
	int n,i;
//	freopen("sort.in","r",stdin);
//  freopen("sort.out","w",stdout);
	while(~scanf("%d",&n)){
		for(i=0;i<n;i++){
			scanf("%s%s",str[i].name,str[i]._score);
			sscanf(str[i]._score,"%lf",&str[i].score);
		}
		stable_sort(str,str+n);
		for(i=0;i<n;i++){
			printf("%s %s\n",str[i].name,str[i]._score);
		}
	}
    return 0;
}
