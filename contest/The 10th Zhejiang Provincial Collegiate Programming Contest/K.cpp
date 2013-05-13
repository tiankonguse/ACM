#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<functional>

#define PI acos(-1.0);
#define inf 0x3ffffffff;
using namespace std;

struct T{
  int c,pre;
}str[555];

bool cmp(T a,T b){
    return a.c > b.c;
}

int num[555];

int main(){

    int n,p,i,max_val,max_pos,min_val,min_pos;
    int cas,ans;
    scanf("%d",&cas);
    while(cas--){
        scanf("%d",&n);
        memset(num,0,sizeof(num));
        for(i=2;i<=n;i++){
            scanf("%d",&str[i].pre);
        }
        p=n-1;
        ans = 0;
        for(i=2;i<=n;i++){
            scanf("%d",&str[i].c);
            if(str[i].pre !=1){
                ans += str[i].c;
            }

        }
        sort(str+2,str+n+1,cmp);
        max_pos=0;
        max_val = 0;

//        printf("---%d  %d\n",p,ans);
        for(i=2;i<=n;i++){
//            printf("--%d  %d  %d\n",str[i].c,str[i].pre,str[i].pos);
//
            if(str[i].pre == 1){
                continue;
            }
            ans -= str[i].c;

            p--;
            num[str[i].pre]++;
            if(num[str[i].pre] > max_val){
                max_val = num[str[i].pre];
                max_pos = i;
            }
//            if(num[str[i].pre] < min_val){
//                min_val = num[str[i].pre];
//                min_pos = i;
//            }

//            printf("--min=%d  max=%d\n",min_val,max_val);
            if(p <= max_val){
                p++;
                ans += str[i].c;
                break;
            }
        }

        printf("%d\n",ans);
    }

    return 0;
}
