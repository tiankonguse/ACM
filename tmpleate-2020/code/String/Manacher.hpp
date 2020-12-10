// 最长回文子串(Manacher) By 猛犸也钻地 @ 2012.11.29

#include <vector>
#include <algorithm>
using namespace std;

// 传入字符串s和长度n，返回最长回文子串的直径，复杂度O(n)
int manacher(const char* s, int n){
    vector<int> u(n+n-1,1); // u[i]表示以i/2为圆心的最长回文子串的直径
    for(int i=1,x=0;i<n+n-1;i++){ // 比如字符串babbaa，看作b.a.b.b.a.a
        u[i]=max(x+u[x]-i,1-i%2); // 相应位置的直径长度就是10301410121
        if(x+x>=i) u[i]=min(u[i],u[x+x-i]);
        int a=(i-1-u[i])>>1,b=(i+1+u[i])>>1;
        while(a>=0 && b<n && s[a]==s[b]) a--,b++,u[i]+=2;
        if(i+u[i]>x+u[x]) x=i;
    }
    return *max_element(u.begin(),u.end());
}
