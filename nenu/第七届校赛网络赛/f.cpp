/*************************************************************************
    > File Name: f.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/13 15:44:14
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;

struct T{
	T(){
		ipv4[0]='\0';
		ipv6[0]='\0';
	}
    char ipv4[16];
	char ipv6[45];
};

map<string,T>host;
char str1[5000];
char str2[5000];
char str3[5000];

int main() {
    string a,b;
    bool fourOrSix;
    int i,j;

    while(gets(str1)){

        if(strcmp(str1,"#HOSTS FILE ENDED") == 0)break;

        if(str1[0] == '#')continue;

        sscanf(str1,"%s%s",str2,str3);

       // printf("---%s  %s\n",str2,str3);


        for(i=0;str3[i];i++){
            if(str3[i] == '#'){
                str3[i] = '\0';
                break;
            }
        }

        host[str3];

        if(strstr(str2,".")){
            if(host[str3].ipv4[0] == '\0'){
                strcpy(host[str3].ipv4,str2);
            }
        }else{
            if(host[str3].ipv6[0] == '\0'){
                strcpy(host[str3].ipv6,str2);
            }
        }
    }



    while(~scanf("%s",str1)){
        if(host.find(str1) != host.end()){
			if(host[str1].ipv4[0]){
				printf("IPv4: %s\n",host[str1].ipv4);
			}
			if(host[str1].ipv6[0]){
				printf("IPv6: %s\n",host[str1].ipv6);
			}
        }else{
			printf("SORRY,I DON'T KNOW.\n");
		}
		puts("");
    }

    return 0;
}
