const int CH=26,N=100000;
int chd[N][CH],sz;
int word[N],fail[N];
int Que[N];
void insert(char *a,int val) {
    int p=0;
    for(; *a; a++) {
        int c=*a - 'a';
        if(!chd[p][c]) {
            memset(chd[sz],0,sizeof(chd[sz]));
            word[sz]=0;
            chd[p][c]=sz++;
        }
        p=chd[p][c];
    }
    word[p]=val;
}
void AC() {
    int *s=Que,*e=Que;
    for(int i=0; i<CH; i++)
        if(chd[0][i]) {
            fail[chd[0][i]]=0;
            *e++=chd[0][i];
        }
    while(s!=e) {
        int p=*s++;
        for(int i=0; i<CH; i++)
            if(chd[p][i]) {
                int v=chd[p][i];
                *e++=v;
                fail[v]=chd[fail[p]][i];
                //word[v]=word[fail[v]];
            } else chd[p][i]=chd[fail[p]][i];
    }
}
void init() {
    memset(word,0,sizeof(word));
    memset(chd[0],0,sizeof(chd[0]));
    sz=1;
}
int main() {
    fail[0]=0;
    init();
}
/*

         int cur=0,ans=0;
         for(int i=0;str[i];i++)
         {
              while(cur&&chd[cur][sw[str[i]]]==0) cur=fail[cur];
              cur=chd[cur][sw[str[i]]];
              int p=cur;
              while(p) ans++,word[p]=0,p=fail[p];
         }
         求出现串 个数
*/
