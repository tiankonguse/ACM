#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<set>
#include<string>
#include<algorithm>
using namespace std;
char str[16][10]={"int","double","float","bool","string","char","integer","vector","map","set","fuck","shit"};
set<string> mys;
int main(){
    freopen("C#.in","w",stdout);
    int t=50;
    srand(time(NULL));
    while(t--){
        mys.clear();
        int n=rand()%100+1;
        printf("%d\n",n);
        for(int i=0;i<n;i++){
            char s[100];
            int l=rand()%30+1;
            for(int i=0;i<l;i++){
                s[i]=rand()%26+'A';if(rand()%2) s[i]+=32;
            }
            s[l]=0;
//            if(mys.find(s)!=mys.end()) puts("#");
            int c=rand()%12;int ty=rand()%4;
            printf("%s %s %d\n",s,str[c],ty);
        }
    }
}
