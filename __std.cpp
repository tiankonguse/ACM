//Orz Sevenkplus
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cctype>
#include<complex>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#define un using namespace
un std;
#define pb push_back
#define mp make_pair
#define c0 first
#define c1 second
#define sqr(x)((x)*(x))
#define clr(x)memset(x,0,sizeof(x))
#define clr1(x)memset(x,-1,sizeof(x))

typedef long long ll;
#ifdef __unix__
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif
typedef pair<int,int> pii;

#define P 1000000007


#define getint(x){\
    char ch;\
    while(!isdigit(ch=getchar()));x=ch-48;\
    while(isdigit(ch=getchar()))x=x*10+ch-48;\
}
#define getint2(x,y){getint(x);getint(y);}
#define getint3(x,y,z){getint(x);getint(y);getint(z);}


#define inf 100000000

int T;
int n,g[120],need,p[120],cc;
char s[120][20],a[120];

class AC{
    public:
        struct node{
            int key,ans,zy;
            int fail;
            int c[26];
        }t[3000];
        int cnt;

        void clear(){
            t[0].zy=0;
            t[0].fail=-1;
            t[0].key=-1;
            t[0].ans=0;
            clr1(t[0].c);
            cnt=1;
        }

        void insert(char *s,int g,int p){
            int n=strlen(s);
            int now=0;
            for(int i=0;i<n;i++){
                if(t[now].c[s[i]-'a']<0){
                    t[now].c[s[i]-'a']=cnt;
                    t[cnt].zy=0;
                    t[cnt].fail=0;
                    t[cnt].key=s[i]-'a';
                    t[cnt].ans=0;
                    memset(t[cnt].c,-1,sizeof t[cnt].c);
                    cnt++;
                }
                now=t[now].c[s[i]-'a'];
            }
            t[now].ans+=g;
            t[now].zy+=p;
        }

        void bfs(){
            int now;
            queue<int> q;
            q.push(0);
            while(!q.empty()){
                now=q.front();
                q.pop();
                for(int j=0;j<26;j++)
                    if(t[now].c[j]>=0){
                        q.push(t[now].c[j]);
                        for(int k=t[now].fail;k>=0;k=t[k].fail)
                            if(t[k].c[j]>=0){
                                t[t[now].c[j]].fail=t[k].c[j];
                                t[t[now].c[j]].ans+=t[t[k].c[j]].ans;
                                t[t[now].c[j]].zy|=t[t[k].c[j]].zy;
                                break;
                            }
                    }
            }
        }

        inline int size(){return cnt;}
}S;

pair<int,int> f[2][260][2000];

void dp(int cs){
    int m=S.size(),l=strlen(a),o=(1<<cc);
    for(int i=0;i<l;i++)a[i]-='a';
    int now=0,past=1;
    for (int j=0;j<o;j++)
            for (int k=0;k<m;k++)
                f[now][j][k]=mp(-200,0);
    f[now][0][0]=mp(0,0);
    for(int i=0;i<l;i++){
        now^=1;
        past^=1;
        for (int j=0;j<o;j++)
            for (int k=0;k<m;k++)
                f[now][j][k]=mp(-200,0);
        for(int j=0;j<o;j++)
            for(int k=0;k<m;k++){
                if(f[past][j][k].first<=-200)continue;
                f[now][j][k]=max(f[now][j][k],mp(f[past][j][k].first-1,f[past][j][k].second));
                int gt=0;
                for(int lk=k;lk>=0;lk=S.t[lk].fail)
                    if(S.t[lk].c[a[i]]>=0){
                        gt=S.t[lk].c[a[i]];
                        break;
                    }
                if (S.t[gt].ans<-50000000)    continue;
                f[now][j|S.t[gt].zy][gt]=max(f[now][j|S.t[gt].zy][gt],mp(f[past][j][k].first,f[past][j][k].second+S.t[gt].ans));
            }
    }
    pair<int,int>ans=mp(-200,0);
    for(int j=0;j<m;j++)
            ans=max(ans,f[now][o-1][j]);
    if(ans.first==-200)
        printf("Case %d: Banned\n",cs);
    else
        printf("Case %d: %d %d\n",cs,-ans.first,ans.second);
}

int main(){
    int t;
    getint(t);
    for(int T=-1;++T!=t;){
        memset(p,0,sizeof p);
        cc=0;
        S.clear();
        need=0;
        getint(n);
        for(int i=0;i<n;i++){
            scanf("%s%d",s[i],g+i);
            if(g[i]==999)g[i]=0,p[i]=(1<<cc),cc++;
            if(g[i]==-999)g[i]=-inf;
            S.insert(s[i],g[i],p[i]);
        }
        scanf("%s",a);
        S.bfs();
        dp(T+1);
    }
    return 0;
}
