#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;
struct T{double fen;char s[33];}str[33];
bool cmp(T a,T b){
	return b.fen < a.fen;
}
int main()
{
	int n,k=1;
	while(cin>>n,n){
		for(int i=0;i<n;i++)cin>>str[i].fen>>str[i].s;
		stable_sort(str,str+n,cmp);
		cout<<"Case "<<k++<<":"<<endl;
		for(int i=0;i<n;i++)printf("%.1f %s\n",str[i].fen,str[i].s);
	}
	
	return 0;
}
