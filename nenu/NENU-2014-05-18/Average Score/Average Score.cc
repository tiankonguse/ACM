#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n;
int main(){
//    freopen("Average_Score.in","r",stdin);
//    freopen("Average_Score.out","w",stdout);
    while(scanf("%d",&n)!=EOF){
        double sums=0;
        double sumc=0;
        for(int i=0;i<n;i++){
            int type;
            scanf("%d",&type);
            if(type==1){
                double c,s;
                scanf("%lf%lf",&c,&s);
                sumc+=c;sums+=s*c;
            }else{
                double c;
                char s[10];
                scanf("%lf%s",&c,s);
                sumc+=c;
                switch(s[0]){
                    case 'A':sums+=95*c;break;
                    case 'B':sums+=85*c;break;
                    case 'C':sums+=75*c;break;
                    case 'D':sums+=65*c;break;
                    case 'E':sums+=30*c;break;
                }
            }
        }
        printf("%.2f\n",sums/sumc);
    }
}
