#include<stdio.h>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
bool map[64];
string s;
vector<string>str;
int len;
int fun(const string s1)
{
	for(int i=1;i<=len;i++)
	{
		if(s1==str[i])return i;	
	}
	return 0;
} 

int main()
{

bool yes;
while(cin>>s)	
{
	yes=true;
	if(!str.empty())str.clear();
	memset(map,false,sizeof(map));
	str.push_back(s);
	str.push_back(s);
	map[1]=map[0]=true;
	len=s.size();
	
	for(int i=2;i<=len;i++)
	{
		string s1=str[i-1];	
		
		char c=s1[0];
		
		s1.erase(s1.begin());
		
		s1+=c;
		
		str.push_back(s1);
	}
	
	for(int i=2;i<=len;i++)
	{
		string s1=s;
		int l=0;
		for(int j=len-1;j>=0;j--)
		{
			l+=(s1[j]-'0')*i;
			s1[j]=l%10+'0';
			l/=10;	
		}
		//cout<<i<<" "<<s1<<endl;
		if(l){yes=false;break;}
		int k=fun(s1);
		if(map[k]){yes=false;break;}
		map[k]=true;		
	}
	if(yes){cout<<s<<" is cyclic"<<endl;}
	else{cout<<s<<" is not cyclic"<<endl;}
	
}
	


return 0;
}
