#include<stdio.h>
#include<string.h>
#include<stdlib.h>
class T{
	public:
	T* next[27];
	int num;
	bool have;	
	T(){memset(next,0,27*sizeof(T*));have=false;}
	char s[16];
}root;
struct TT{char s[16];int num;}str0[100000];
int cmp(void const* a,void const* b){
	return ((struct TT const*)a)->num - ((struct TT const*)b)->num;
}
void insert(char str[],int num){
	T * p=&root;
	int c;
	for(int i=0;str[i];i++){
		c=str[i]-'a';
		if(p->next[c]==0){
			p->next[c]=new T();
		}
		p=p->next[c];
	}
	strcpy(p->s,str);
	p->have=true;
	p->num=num;
}

void read(){
	char str[17];
	int i=0;
	while(scanf("%s",str),str[0]^'#'){
		insert(str,i++);
	}
}
bool find(char str[]){
	T * p=&root;
	int c;
	for(int i=0;str[i];i++){
		c=str[i]-'a';
		if(p->next[c]==0)return false;
		p=p->next[c];
	}
	return p->have;
}
void ifdelete(char str[],int& i){
	T * p=&root;
	for(int j=0;str[j];j++){
		T * q=p;
		int k=j+1;
		for(;q!=0 && str[k];k++){
			if(q->next[str[k]-'a']==0)break;
			q=q->next[str[k]-'a'];
		}
		if(q!=0 && str[k]==0 && q->have){
			str0[i].num=q->num;
			strcpy(str0[i].s,q->s);
			i++;
		}
		
		if(p==0)break;
		p=p->next[str[j]-'a'];
	}
}
void ifreplace(char str[],int& i){
	T * p=&root;
	int c;
	for(int j=0;str[j];j++){
		c=str[j]-'a';
		for(int h=0;h<26;h++){
			if(h==c )continue;
			T * q=p->next[h];			
			int k=j+1;
			for(;q!=0 && str[k];k++){
				if(q->next[str[k]-'a']==0)break;
				q=q->next[str[k]-'a'];
			}
			if(q!=0 && str[k]==0 && q->have){
				str0[i].num=q->num;
				strcpy(str0[i].s,q->s);
				i++;
			}
		}
		p=p->next[c];
		if(p==0)break;
	}
}
void ifinsert(char str[],int& i){
	T * p=&root;
	int c;
	
	for(int j=0;str[j];j++){
		for(int h=0;h<26;h++){
			T * q=p->next[h];
			int k=j;
			for(;q!=0 && str[k];k++){
				if(q->next[str[k]-'a']==0)break;
				q=q->next[str[k]-'a'];
			}
			if(q!=0 && str[k]==0 && q->have){
				str0[i].num=q->num;
				strcpy(str0[i].s,q->s);
				i++;
			}
		}
		p=p->next[str[j]-'a'];
		if(p==0)break;
	}
if(p==0)return;
	//p=&root;
	//for(int j=0;str[j];j++){
	//	if(p->next[str[j]-'a']==0)return ;
	//	p=p->next[str[j]-'a'];
	//}
	for(int j=0;j<26;j++){
		T * q=p->next[j];
		if(q!=0 && q->have){
			str0[i].num=q->num;
			strcpy(str0[i].s,q->s);
			i++;
		}
	}

}
void check(){
	char str[17];
	while(scanf("%s",str),str[0]^'#'){
		if(find(str))printf("%s is correct\n",str);
		else{
			int i=0;
			ifdelete(str,i);
			ifreplace(str,i);
			ifinsert(str,i);
			if(i)qsort(str0,i,sizeof(TT),cmp);
			printf("%s:",str);
			for(int j=0;j<i;j++){
				if(j && str0[j].num==str0[j-1].num)continue;
				printf(" %s",str0[j].s);
			}
			printf("\n");
		}
	}
}

int main(){
	root.have=false;
	read();
	check();
	return 0;
}
