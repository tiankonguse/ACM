/*************************************************************************
    > File Name: A密码02.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/15 20:36:46
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;

using namespace std;
const int P=101000;
int next[P];
char str[P];
//next[i]的意义
//s为匹配串,t为s的前i个字符组成的子串
//t = s[0]s[1]...s[i-1]
//设串s[0]s[1]...s[k]和串s[i-1-k]s[i-1-(k-1)]...s[i-1]相等，
//next[i]就是这样的k的最大值
//

int get_next(char *pat,int &len){
	memset(next,-1,sizeof(next));
	int mid = -1,i,k;
	for(i=1;pat[i];++i){
		for(k=next[i-1];k>=0 && pat[i]!=pat[k+1];k=next[k]);
		if(pat[k+1] == pat[i])next[i]=k+1;
		if(pat[i+1] && next[i] > mid)mid = next[i];
	}
	len = i;
	return mid;
}

//返回匹配的第一个位置
//返回匹配的个数  ans
int kmp( char* pat){
	int j;
	int now =  get_next(pat,j)+1 ;
	while(j> now){
        j = next[j-1]+1;
	}
	return j;
}


int main() {
    int len,i,pre;
    while(~scanf("%s",str)){
        pre = kmp(str);
        str[pre] = '\0';
        printf("%s\n",str);
    }
    return 0;
}
