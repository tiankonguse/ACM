// 后缀数组(倍增算法) By 猛犸也钻地 @ 2012.02.02

#include <algorithm>
using namespace std;

class SuffixArray {
public:
    // 数组下标和后缀顺序都从0开始标号，注意排序后最小的串为空串
    // sa[i]表示第i小的后缀从字符串的第sa[i]个位置开始
    // rk[i]表示字符串第i个位置开始的后缀是第rk[i]小的字符串
    // ht[i]表示sa[i]和sa[i-1]所代表的字符串的公共前缀的长度
    static const int SIZE = 100005;
    int sa[SIZE],rk[SIZE],ht[SIZE],tmp[SIZE*2],len;
    struct Indexer {
        int& len,* tmp;
        bool operator ()(int x, int y) const {
            if(tmp[x]!=tmp[y]) return tmp[x]<tmp[y];
            return tmp[x+len]<tmp[y+len];
        }
    };
    // 对字符串s[0..n-1]做后缀排序，s[n]必须为'\0'
    // 排序后的sa[0]是后缀"\0"，sa[1..n]为一般后缀
    // 对于int类型的串，同样需保证有且仅有s[n]的值为0
    void gao(const char* s, int n){
        Indexer cmp={len,tmp};
        for(int i=0;i<=n;i++) rk[sa[i]=i]=s[i];
        for(len=1;rk[sa[n]]!=n;len<<=1){
            copy(rk,rk+n+1,tmp);
            sort(sa,sa+n+1,cmp);
            for(int i=rk[*sa]=0;i<n;i++)
                rk[sa[i+1]]=rk[sa[i]]+cmp(sa[i],sa[i+1]);
        }
        for(int i=len=ht[*sa]=0;i<n;i++){
            if(len) --len;
            while(s[i+len]==s[sa[rk[i]-1]+len]) len++;
            ht[rk[i]]=len;
        }
    }
};
