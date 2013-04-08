#include<stdio.h>
#include<stack>
#include<string.h>
#define MAX 130
using namespace std;
stack<char>a;
int main(){
	int n,i,m;
	int priority[MAX];
	char p[MAX];
	while(!a.empty()) a.pop();
	priority['(']=priority[')']=0;
	priority['[']=priority[']']=1;
	scanf("%d",&n);
	getchar();
	while(n--){
	gets(p);
	m=strlen(p);
	p[m]='\0';
	a.push(p[0]);
	for(i=1;p[i]!='\0';i++){
		if(!a.empty()&&priority[a.top()]==priority[p[i]]){
			if((p[i]==')'&&a.top()=='(')||(p[i]==']'&&a.top()=='[')){
				a.pop();
				}
			else{
				a.push(p[i]);
				}
			}
		else{
			a.push(p[i]);
			}
		}
	if(!a.empty()) {
		printf("No\n");
		while(!a.empty()){
			a.pop();
			}
		}
	else printf("Yes\n");
	}
return 0;
}

