#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif


const int kind = 10,N=100000*40;
int tire[N][kind];
char word[N][50];
int size = 0;

void init() {
    memset(word,0,sizeof(word));
    memset(tire[0],0,sizeof(tire[0]));
    size=1;
}
void insert(char *str, char* val) {
    int p = 0, i;
    for(; *str; str++) {
        i = *str - '0';
        if(!tire[p][i]) {
            memset(tire[size],0,sizeof(tire[size]));
            word[size][0]='\0';
            tire[p][i]= size++;
        }
        p = tire[p][i];
    }
    strcpy(word[p],val);
}

char* query(char* str) {
    int i,j,p = 0;
    for(; *str; str++) {
        i= *str-'0';
        j = 1 - i;
        if(tire[p][j]){
        	p = tire[p][j];
        }else{
        	p = tire[p][i];
        }
    }
    return word[p];
}



void add(char* old){
	char s[64];
	LL in;
	sscanf(old,"%lld",&in);
	s[32] = '\0';
	for(int i=31;i>=0;i--){
		s[i] = (in&1) + '0';
		in >>= 1;
	}
	insert(s, old);
}


void search(char* old){
	char s[64];
	LL in;
	sscanf(old,"%lld",&in);
	s[32] = '\0';
	for(int i=31;i>=0;i--){
		s[i] = (in&1) + '0';
		in >>= 1;
	}
	printf("%s\n",query(s));
}

int main(int argc, char* argv[]) {
	int n,m;
	int i,j;
	LL _,__;
	char in[100];
	scanf("%lld",&__);
	for(_ =1; _ <= __; _++){
		scanf("%d%d",&n,&m);
		init();
		for(i=0;i<n;i++){
			scanf("%s",in);
			add(in);
		}
		printf("Case #%lld:\n",_);
		while(m--){
			scanf("%s",in);
			search(in);
		}
	}

    return 0;
}






