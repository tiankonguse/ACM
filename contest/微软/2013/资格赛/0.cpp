//source here
#/**************************************************************************
 **      File Name: 传话游戏.cpp
 **      Author: tiankonguse
 **      Mail: shen10000shen@gmail.com
 **      Created Time: 2013/4/6 10:03:33
/**************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;

int main(){
    typedef long long LL;
    map<string,string>::iterator it;
    int cas,n,m,num,i,j=1;
    string s[100];
    char _s[200];
    char *p;
    string left,right,tmp;
    scanf("%d",&cas);
    while(cas--){
        map<string,string>mymap;
        scanf("%d%d",&n,&m);
        getchar();
        while(m--){
            gets(_s);
            left = strtok(_s, " ");
            right = strtok(NULL, " ");
            mymap[left]=right;
        }
        gets(_s);

        p = strtok(_s, " ");
        num=0;
        while(p){
            s[num++]=p;
            p = strtok(NULL, " ");
        }
        n--;
        while(n--){
            for(i=0;i<num;i++){
                it = mymap.find(s[i]);
                if(it != mymap.end()){
                    s[i] = mymap[s[i]];
                }
            }
        }
        cout<<"Case #"<<j++<<": "<<s[0];
        for(i=1;i<num;i++){
            cout<<" "<<s[i];
        }
        cout<<endl;
    }


    return 0;
}
