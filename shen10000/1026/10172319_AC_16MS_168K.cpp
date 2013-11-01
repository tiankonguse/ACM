#include<stdio.h>
#include<string.h>
int str0[202];
bool map[202];
char str1[202];
char str2[202];
char tmp1[402];
int  tmp0[402];
int n;
void print_i(int *p,int l){
	for(int i=0;i<l;i++){
		printf("%d ",p[i]);
	}
	printf("\n");
}
void print_c(char *p,int l){
	for(int i=0;i<l;i++){
		printf("%c ",p[i]);
	}
	printf("\n");
}

void read(){
	getchar();
	gets(str1);
	int l=strlen(str1);
	for(;l<n;l++)str1[l]=' ';
	str1[l]='\0';
	str2[l]='\0';
	
}

int find(int beg){
	int l=0;
	int now=beg;
	
	tmp0[l]=now;	
	tmp1[l]=str1[now];
	now=str0[now];
	l++;
	
	
	
	for(;now^beg;){
		tmp0[l]=now;	
		tmp1[l]=str1[now];
		now=str0[now];
		l++;
	}
	
	return l;
}

void fun(int k,int l){

	for(int i=l,j=0;j<k;j++,i++){
		tmp1[i]=tmp1[j];
		tmp0[i]=tmp0[j];
	}
	for(int i=0,j=k;i<l;i++,j++){
		str2[tmp0[j]]=tmp1[i];
		map[tmp0[j]]=false;
	}

}



int main(){
	int k;
	while(scanf("%d",&n),n){
		for(int i=0;i<n;i++){
			scanf("%d",&str0[i]);
			str0[i]--;
		}
	
		while(scanf("%d",&k),k){
			read();
			memset(map,true,sizeof(map));
			
			for(int i=0; i^n;i++){
				if(map[i]){
					int l=find(i);
					fun(k%l,l);
				}
			}
			printf("%s\n",str2);

		}
		printf("\n");
	}
return 0;	
}
