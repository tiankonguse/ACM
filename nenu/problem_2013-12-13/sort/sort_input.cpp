#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<ctime>
#include<stack>
#include<algorithm>
#include<functional>
#include<stdarg.h>
using namespace std;
#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif

void getName(char* name, int minLen, int maxLen){
	int len = rand()%(maxLen-minLen) + minLen;
	for(int i=0;i<len;i++){
		name[i] = rand()%26 + 'a';
	}
	name[len] = '\0';
}


void getScore(char* score, int minScore, int maxScore, int dotLen){
	int nowScore = rand()%(maxScore-minScore) + minScore;
	sprintf(score,"%d",nowScore);
	bool haveFloat = rand()%2;
	if(haveFloat){
		int len = strlen(score);
		score[len++] = '.';
		int numLen = rand()%dotLen + 1;
		while(numLen--){
			score[len++] = rand()%10 + '0';
		}
		score[len++] = '\0';
	}
}

int main() {
    freopen("sort.in","w",stdout);
    srand(time(NULL));
    int k=20;
    int _max = 1000;
    char name[100];
    char score[1000];
    int nameLen = 8;
    int maxScore = 1000;
    int n;

    while(k--){
    	n = rand()%_max + 1;
    	printf("%d\n",n);
    	while(n--){
    		getName(name,2,nameLen);
    		getScore(score,0,maxScore,5);
    		printf("%s %s\n",name,score);
    		if(rand()%2 && n){
    			int len = strlen(name);
    			name[len++] = 'a';
    			name[len++] = '\0';

				printf("%s %s\n",name,score);
				n--;
    		}
    	}
    }

    return 0;
}
