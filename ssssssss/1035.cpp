#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std; 
int n,m,Ans,k; 
struct TT{
	int a,b;
}str[4012];

bool cmp(struct TT bb,TT aa){
	return aa.a < bb.a;
}
void  Init() { 

    scanf("%d %d",&n,&m);
	k=0;    
    for (int i=1;i<n;i++) { 
        scanf("%d",&(str[k].a)); 
        str[k].b=1; 
        k++;
    } 
    for (int i=1;i<m;i++) { 
        scanf("%d",&(str[k].a)); 
        str[k].b=2; 
        k++;
    } 
 
    sort(str,str+k,cmp); 

 } 
void Slove() 
{ 
	Ans=0;
    int x=0,y=0; 
    for (int i=0;i<k;i++) 
        if (str[i].b==1) { 
            Ans+=str[i].a*(y+1); 
            x++; 
        } 
        else { 
            Ans+=str[i].a*(x+1); 
            y++;
        } 
    printf("%d\n",Ans); 
} 
int main() 
{ 
    Init();
	Slove(); 
    return 0; 
} 
