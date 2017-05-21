#include"iostream"
#include"queue"
#define MAXN 101
#define WORD_LEN 21
#define MAX_WORD 26
using namespace std;
struct Trie_Node{
    int id;
    Trie_Node *next[MAX_WORD];
    void init(){
         id=-1;
         memset(next,NULL,sizeof(next));
    }
}trie[MAXN*WORD_LEN],root;
int tidx,cnt;
int insert(char* s){
    int i,j;
    Trie_Node *p=&root;
    for(i=0;s[i];i++){
        j=s[i]-'a';
        if(p->next[j]==NULL){
            trie[tidx].init();
            p->next[j]=&trie[tidx++];
        }
        p=p->next[j];
    }
    if(p->id==-1)p->id=cnt++;
    return p->id;
}
void init_trie(){
    tidx=cnt=0;
    root.init();
}

int K;
int ori[MAXN];
char str[WORD_LEN];
struct matrix{
    int N;
    int mat[MAXN][MAXN];
    void init();
}A,B;
void matrix::init(){
    int num,id,d;
    scanf("%d%d",&N,&K);
    init_trie();
    memset(mat,0,sizeof(mat));
    for(int i=0;i<N;i++){
        scanf("%s %d %d",str,&d,&num);
        id=insert(str);
        ori[id]=d;
        for(int j=0;j<num;j++){
            scanf(" %s",str);
            mat[insert(str)][id]++;
        }
    }
    for(int i=0;i<N;i++)mat[i][i]^=1;
}
matrix operator +(matrix A,matrix B){
    matrix C;
    C.N=A.N;
    for(int i=0;i<A.N;i++){
        for(int j=0;j<A.N;j++){
            C.mat[i][j]=(A.mat[i][j]+B.mat[i][j])&1;
        }
    }
    return C;
}
matrix operator *(matrix A,matrix B){
    matrix C;
    C.N=A.N;
    memset(C.mat,0,sizeof(C.mat));
    for(int i=0;i<A.N;i++){
        for(int j=0;j<A.N;j++){
            if(A.mat[i][j]){
               for(int k=0;k<A.N;k++){
                   C.mat[i][k]=(C.mat[i][k]+A.mat[i][j]*B.mat[j][k])&1;
               }
            }
        }
    }
    return C;
}
matrix operator ^(matrix A,int n){
    matrix C;
    C.N=A.N;
    memset(C.mat,0,sizeof(C.mat));
    for(int i=0;i<C.N;i++)C.mat[i][i]=1;
    while(n){
        if(n&1)C=C*A;
        A=A*A;
        n>>=1;
    }
    return C;
}
void print(matrix a){
    for(int i=0;i<a.N;i++){
        for(int j=0;j<a.N;j++){
            if(j==a.N-1)printf("%d\n",a.mat[i][j]);
            else printf("%d ",a.mat[i][j]);
        }
    }
}
int main(){
    int T,s,cnt;
    scanf("%d",&T);
    while(T--){
        A.init();
      //  print(A);
        B=A^(K-1);
     //   print(B);
        cnt=0;
        for(int i=0;i<B.N;i++){
            s=0;
            for(int j=0;j<B.N;j++){
                s=(s+B.mat[i][j]*ori[j])%2;
            }
            if(s)cnt++;
        }
        printf("%d\n",cnt);
    }
   // system("pause");
    return 0;
}
