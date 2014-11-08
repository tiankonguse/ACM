// 字符串前缀匹配(KMP)和后缀匹配(Z-Function) By 猛犸也钻地 @ 2012.02.02

#include <vector>
#include <algorithm>
using namespace std;

// 计算字符串s[0..n-1]的前缀函数(KMP)，复杂度O(n)
// P[0]=0，对其他的i，有最大的P[i]，使得s[0..P[i]-1]等于s[i-P[i]+1..i]
vector<int> calcP(const char* s, int n){
    vector<int> P(n);
    for(int x=0,y=1;y<n;y++){
        while(x && s[x]!=s[y]) x=P[x-1];
        if(s[x]==s[y]) P[y]=++x;
    }
    return P;
}

// 计算字符串s[0..n-1]的后缀函数(Z-Function)，复杂度O(n)，俗称扩展KMP
// Z[0]=0，对其他的i，有最大的Z[i]，使得s[0..Z[i]-1]等于s[i..i+Z[i]-1]
vector<int> calcZ(const char* s, int n){
    vector<int> Z(n);
    for(int i=1,x=0,y=0;i<n;i++){
        if(i<=y) Z[i]=min(y-i,Z[i-x]);
        while(i+Z[i]<n && s[i+Z[i]]==s[Z[i]]) Z[i]++;
        if(y<=i+Z[i]) x=i,y=i+Z[i];
    }
    return Z;
}
