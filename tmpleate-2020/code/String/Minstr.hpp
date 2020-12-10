// 循环字符串最小表示 By 猛犸也钻地 @ 2011.11.24

#include <algorithm>
using namespace std;

// 传入字符串s和长度n，返回该循环字符串最小表示的首字符下标，复杂度O(n)
int minstr(const char* s, int n){
    int i=0,j=1,x=0;
    while(i<n && j<n && x<n){
        char u=s[i+x<n?i+x:i+x-n];
        char v=s[j+x<n?j+x:j+x-n];
        if(u>v) i=max(i+x,j)+1;
        if(u<v) j=max(j+x,i)+1;
        if(u==v) x++; else x=0;
    }
    return min(i,j);
}
