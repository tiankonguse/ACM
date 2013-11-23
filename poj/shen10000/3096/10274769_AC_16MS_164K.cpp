#include<iostream>
using namespace std;
char s[100];
int main()
{
	int len,i,j,d,dmax;
	bool flag;
	while(scanf(" %s",&s),s[0]^'*')
	{
		len=strlen(s);
		if(len<2) { printf("%s is surprising.\n",s); continue;}
		dmax=len-1;
		flag=true;
		for(d=1;d<=dmax ;d++)
			for(i=0;i<len && i+d<len ;i++)
				for(j=i+1;j<len && j+d<len;j++)
					if(s[j]==s[i] && s[j+d]==s[i+d]) {flag=false;goto dis;}

dis:;
		if(flag) printf("%s is surprising.\n",s);
		else printf("%s is NOT surprising.\n",s);
	}
	return 0;
}
