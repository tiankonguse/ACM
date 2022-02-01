#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define maxn 1007
#define eps 1e-7
using namespace std;

#ifdef __int64
    typedef __int64 LL;
#else
    typedef long long LL;
#endif

const LL mod = 1000000007;
struct T{
	char endChar;
	int allNum;
	void init(){
		allNum = endChar = 0;
	}
}str[30];

LL gt[111];
bool invalid;

//0 null, 1 yes, 2 all, 3 head, 4 end
int isMid[30];
int isMid[30];

int n;

void  init(){
    gt[0]=gt[1]=1;
    for(LL i=2;i<=100;i++){
        gt[i]=i*gt[i-1]%mod;
    }
    invalid = false;
    memset(isMid, 0, sizeof(isMid));
    for(int i=0;i<26;i++){
		str[i].init();
    }

}


void trim(char* line){
	char c = line[0];
	int p = 1;
	for(int i=1;line[i];i++){
		if(line[i] != c){
			c = line[p++] = line[i];
		}
	}
	line[p] = '\0';
}


void read(){
	char s[maxn];
	scanf("%lld",&n);
	while(n--){
		scanf("%s",s);
		if(invalid)continue;
		trim(s);
		int l = strlen(s);
		if(l == 1){
			if(isMid[s[0]] == 1){
				invalid = true;
				continue;
			}else if(isMid[s[0]] == 0){
				isMid[s[0]] = 2;
			}
			str[s[0]].allNum++;
			continue;
		}else if(l == 2){
			if(isMid[s[0]] == 1){
				// 两个在中间
				invalid = true;
				continue;
			}else if(isMid[s[0]] == 3){
				//一个在中间，一个在头部
				invalid = true;
				continue;
			}


		}else{

		}

	}

}

int main(){
//    freopen("B-small-attempt0 (4).in","r",stdin);
//    freopen("output.txt","w",stdout);
    LL _,cas=1,n;
    scanf("%lld",&_);
    while(_--){
    	init();
    	read();


        bool ok=true;


        LL ans=1;
        LL cc=0;
        for(LL i='a';i<='z';i++){
            if(w[i]>1)ok=false;
            if(t[i]>1)ok=false;
            if(w[i]==0&&t[i]==0&&vis[i])cc++;
            ans*=gt[cnt[i]];
            ans%mod;
        }
        bool fine = true;
        for(LL i=0;i<c;i++){
            LL now = str[i].t;
            for(LL j=0;j<c;j++){
                if(now==str[j].w)fine=false;
            }
            if(fine==true)break;
        }
        if(!fine)ok=false;
        printf("Case #%lld: ",cas++);
        if(!ok){puts("0");continue;}

        memset(vis,0,sizeof vis);
        memset(who,-1,sizeof who);
        for(LL i=0;i<c;i++){
            next[str[i].t]=str[i].w;
            who[str[i].t]=i;
        }
        for(LL i=0;i<c;i++){
            if(vis[i])continue;
            dfs(i);
            cc++;
        }
        ans*=gt[cc];
        ans%=mod;
        printf("%lld\n",ans);
    }
    return 0;
}

/*
2
sas
asa

*/
