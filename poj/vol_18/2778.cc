#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxm 12
#define size 4
#define leng 12
#define maxn 105
using namespace std;
int chr[128];
int root, idx;
struct trie_node{
    int next[size];
    int fail;
    bool flag;
    void init(){
        flag = false, fail = -1;
        memset(next, 0, sizeof(next));
    }
}trie[maxm * leng];
int q[maxm * leng];
void trie_init(){
    root = idx = 0;
    trie[root].init();
}
void insert(char *s){
    int i, j, p = root;
    for(i=0;s[i];i++){
        j = chr[s[i]];
        if(!trie[p].next[j]){
            trie[++idx].init();
            trie[p].next[j] = idx;
           // printf("%c: %d\n", s[i], idx);
        }
        p = trie[p].next[j];
    }
    trie[p].flag = true;
}
void build(){
    int i, j, tmp;
    q[0] = root;
    for(int l=0,h=1;l<h;){
        tmp = q[l++];
        for(j=0;j<size;j++){
            if(trie[tmp].next[j]){
                q[h++] = trie[tmp].next[j];
                if(trie[tmp].fail == -1) trie[trie[tmp].next[j]].fail = root;
                else{
                    trie[trie[tmp].next[j]].fail = trie[trie[tmp].fail].next[j];
                    trie[trie[tmp].next[j]].flag |= trie[trie[trie[tmp].fail].next[j]].flag;
                }
            //    printf("trie[%d].fail = %d\n", trie[tmp].next[j], trie[trie[tmp].next[j]].fail);
            }
            else{
                if(trie[tmp].fail != -1){
                    trie[tmp].next[j] = trie[trie[tmp].fail].next[j];
                }

            }
        }
    }
}

const long long mod = 100000LL;
struct matrix{
    int n;
    __int64 mat[maxn][maxn];
    void init(){
        n = idx + 1;
        memset(mat, 0, sizeof(mat));
        for(int i=0;i<=idx;i++){
            if(trie[i].flag) continue;
            for(int j=0;j<4;j++){
                if(!trie[trie[i].next[j]].flag)
                mat[trie[i].next[j]][i]++;
            }
        }
    }
    matrix operator+(matrix B){
        matrix C;
        C.n = n;
        //memset(C.mat, 0, sizeof(C.mat));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                C.mat[i][j] = (mat[i][j] + B.mat[i][j]) % mod;
            }
        }
        return C;
    }
    matrix operator*(matrix B){
        matrix C;
        C.n = n;
        memset(C.mat, 0, sizeof(C.mat));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]){
                    for(int k=0;k<n;k++){
                        C.mat[i][k] = (C.mat[i][k] + mat[i][j] * B.mat[j][k]) % mod;
                    }
                }
            }
        }
        return C;
    }
    matrix operator^(int m){
        matrix C;
        C.n = n;
        memset(C.mat, 0, sizeof(C.mat));
        for(int i=0;i<n;i++) C.mat[i][i] = 1;
        while(m){
            if(m & 1) C = C * (*this);
            *this = (*this) * (*this);
            m >>= 1;
        }
        return C;
    }
    void print(){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j == n - 1) cout<<mat[i][j]<<endl;
                else cout<<mat[i][j];
            }
        }
    }
}A, B, C;

char word[leng];
int main(){
   // freopen("27781.txt","w",stdout);
    chr['A'] = 0, chr['T'] = 1, chr['G'] = 2, chr['C'] = 3;
    int m, n;
    while(~scanf("%d%d", &m, &n)){
        trie_init();
        for(int i=0;i<m;i++){
            scanf(" %s", word);
            insert(word);
        }
        build();
        A.init();

     //   A.print();
        B = A ^ n;
    //  B.print();
        __int64 res = 0;
        for(int i=0;i<=idx;i++){
            if(!trie[i].flag) res = (res + B.mat[i][0]) % mod;
        }
        printf("%I64d\n", res);
    }
    return 0;
}
