#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;

void isletter(char &c){
	if(c>='a' && c<='z'){
		c=c-'a'+'A';
		return ;
	}
	if(c>='A' && c<='Z'){
		c=c-'A'+'a';
		return ;
	}
}

int main()
{
	char str[111];
	while(gets(str)){
		if(str[0]=='.' && str[1]=='\0')break;
		if(str[0]=='@'){
			isletter(str[1]);
		}
		for(int i=1;str[i];i++){
			if(str[i]=='@'){
				isletter(str[i-1]);
				isletter(str[i+1]);
			}
		}
		for(int i=0;str[i];i++){
			if(str[i]^'@')printf("%c",str[i]);
		}
		puts("");
	}
	return 0;
}
