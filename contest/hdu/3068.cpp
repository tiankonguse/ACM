/*
Manacher算法--O（n）回文子串算法
*/

#include<iostream>
#include<cstdio>
#include<set>
#include<cstring>
#include<cstdlib>
#include<functional>
#include<functional>
#include<algorithm>
using namespace std;

const int MAX = 110003 << 2;
char oldstr[MAX];//原字符串
char str[MAX];
int p[MAX];//表示以i为中心的回文半径，
/*
p[i]-1刚好是原字符串以第i个为中心的回文串长度。
*/

void Manacher(int n){

    int mx=0;//记录前面回文串最长影响到的地方。不一定是最长回文串造成的。
    int id;//最长影响串的位置;
    p[0]=0;

    for(int i = 1; i < n; i++){
        p[i]=1;//至少是1
        if(mx>i){
            //i受到影响即，id+p[id]-1>=i;
            p[i] = p[2 * id - i];//2*id-i是i关于id的对称点相当于是id-(i-id);
            if(mx - i < p[i]) p[i] = mx - i;
            //由于对称点的回文半径可能超过mx-i,因为mx后面的还没有配过
            //所以要取小的。
        }

        //向两端配匹
        while(str[i - p[i]] == str[i + p[i]]) p[i]++;

        if(i + p[i] > mx){
            mx = i + p[i];
            id = i;
        }
        //printf("i=%d  str=%c  p=%d\n",i,str[i],p[i]);
    }
}

/*
预处理字符串
*/
int pre(char head='$', char middle='#', char end = '?'){
    int n=0;

    str[n++]=head;
    str[n++]=middle;

    for(int i = 0; oldstr[i]; i++){
        str[n++] = oldstr[i];
        str[n++] = middle;
    }

    str[n]=end;

    return n;
}

int main(){

    int n;

    while(scanf("%s", oldstr) != EOF){

        n = pre();

        Manacher(n);

        int ans=0;

        for(int i = 1; i < n; i++){
            if(p[i] > ans) ans = p[i];
        }

        printf("%d\n", ans - 1);
    }
    return 0;
}
