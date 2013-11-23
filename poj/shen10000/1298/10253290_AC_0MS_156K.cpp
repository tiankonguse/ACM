#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char map[27];
char str[200];
char *endofinput="ENDOFINPUT";
void init(){
	for(int i=0;i<5;i++){
		map[i]='V'+i;
	}
	for(int i=5,j=0;i<26;i++,j++){
		map[i]='A'+j;
	}	
}

void output(char* p){
	
	while(*p){
		if(*p>='A' && *p<='Z')*p=map[*p-'A'];
		p++;
	}
}

int main()
{
init();
while(gets(str)){
	if(strcmp(str,endofinput)==0)break;
	gets(str);
	output(str);
	puts(str);
	gets(str);
}

return 0;
}
