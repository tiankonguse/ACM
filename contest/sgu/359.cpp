#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int pa[10],pb[10];
char str[100];

int main(){
    int n;
    //freopen("1.txt","r",stdin);
    scanf("%d",&n);
    for (int i=0; i<10; ++i) pa[i]=i;
    for (;n;--n){
        scanf("%s",str);
        if (str[0]=='w'){
            int c=str[8];
            printf("%d\n",pb[pa[c-'a']]);
            continue;
        }
        int c=str[0]-'a';
        if (str[2]==':') {
            int d=str[4];
            //cout<<d-'a'<<" "<<(char)d<<endl
            if(d>='0' && d<='9')
                pb[pa[c]]=d-'0';
            else pb[pa[c]]=pb[pa[d-'a']];
            continue;
        }
        int d=str[3]-'a';
        pa[c]=pa[d];
    }
}
