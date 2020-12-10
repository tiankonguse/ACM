// 确定性AC自动机(Trie图) By 猛犸也钻地 @ 2011.11.24

#include <cstring>
#include <algorithm>
using namespace std;

class TrieGraph {
public:
    static const int SIZE = 100005; // 最大结点总数，约为模板串长度之和
    static const int LEAF = 26;     // 每个结点下的叶子数量
    // next[]指向了含有相同后缀但更短的一个字符串，n为当前存在的结点总数
    int next[SIZE],e[SIZE][LEAF],n; // e[][]为结点的各个叶子的编号
    int data[SIZE]; // data[]一般用位标记维护当前的串匹配上了哪些模式串
    TrieGraph(){n=SIZE;}    // 别忘了写上这行
    void init(){
        fill_n(next,n,0);
        fill_n(data,n,0);
        memset(e,-1,n*sizeof(e[0]));
        n=1;
    }
    void insert(const char* s, int idx = 0){
        int x=0;
        for(int i=0;s[i];i++){
            int c=s[i]-'a'; // 根据题目的字符集修改这里的映射方式
            x=~e[x][c]?e[x][c]:e[x][c]=n++;
        }
        data[x]|=1<<idx;
    }
    void make(){
        static int q[SIZE],m;
        next[0]=m=0;
        for(int c=0;c<LEAF;c++)
            if(~e[0][c]) next[q[m++]=e[0][c]]=0; else e[0][c]=0;
        for(int i=0;i<m;i++){
            int x=q[i];
            data[x]|=data[next[x]]; // 求next[]路径上的前缀和
            for(int c=0;c<LEAF;c++){
                int t=e[next[x]][c];
                if(~e[x][c]) next[q[m++]=e[x][c]]=t; else e[x][c]=t;
            }
        }
    }
};
