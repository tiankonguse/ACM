
#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
char s[1000];
int main(){
   while(scanf("%s",s)!=EOF)
   {
       int len = strlen(s);
       for(int i=0;i<len;i++)
       {
           if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9'))
            cout<<s[i];

       }cout<<endl;
   }
}
