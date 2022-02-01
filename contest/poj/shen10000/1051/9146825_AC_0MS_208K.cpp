#include<iostream>
#include<string>
#include<vector>
using namespace std;
int str1[40],map[100],m;
char str0[40],str4[110],str5[500];
vector<string>str3;
string s1,s2,s4;
void makeset()
{
	for(int i=0;i<26;i++)str0[i]='A'+i;
	str0[26]='_';str0[27]=',';str0[28]='.';str0[29]='?';
	
str3.push_back(".-");    str3.push_back("-...");  
str3.push_back("-.-.");str3.push_back("-..");
str3.push_back(".");str3.push_back("..-.");
str3.push_back("--.");str3.push_back("....");
str3.push_back("..");str3.push_back(".---");
str3.push_back("-.-");  str3.push_back(".-..");  
str3.push_back("--");  str3.push_back("-.");  
str3.push_back("---");  str3.push_back(".--.");  
str3.push_back("--.-");  str3.push_back(".-.");  
str3.push_back("...");  str3.push_back("-");  
str3.push_back("..-");  str3.push_back("...-");  
str3.push_back(".--");  str3.push_back("-..-");  
str3.push_back("-.--");   str3.push_back("--..");
str3.push_back("..--");str3.push_back(".-.-");
str3.push_back("---.");str3.push_back("----");

for(int i=0;i<30;i++)
	str1[i]=str3[i].size();
	
}

int find(const char c)
{
	for(int i=0;i<30;i++)
		if(c==str0[i])
		{
			s1+=str3[i];
			return str1[i];	
		}
}
void born()
{
	for(int i=0;;i++)
	if(str3[i]==s4)
	{
		s2+=str0[i];
		return;
	}		
}

void changnum()
{
	for(int i=0;i<m;i++)
	{
		map[i]=find(str4[i]);
	}
	int j=0;
	for(int i=m-1;i>=0;i--)
	{
		s4="";
		while(map[i]--)
		{
			s4+=s1[j];
			j++;
		}
		born();	
	}	
}
int main()
{
	makeset();
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		s1="";
		s2="";
		scanf("%s",str4);
		m=strlen(str4);
		changnum();
		cout<<i<<": "<<s2<<endl;
		
	}

return 0;
}
