#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
const int size=200;
const int maxsize=100000;

struct book{
	char title[size];
	char author[size];
	int tag;
}b[maxsize],r[maxsize];

int cmp(book a,book b){
	int tmp=strcmp(a.author,b.author);
	if(tmp==0 && strcmp(a.title,b.title)<0)return true;
	return tmp<0?true:false;
}

int read(){
	char tmp[size];
	int k=0,i,j;
	while(gets(tmp) && tmp[0]!='E'){
		
		b[k].title[0]=tmp[0];
		for(i=1;tmp[i]!=tmp[0];i++)b[k].title[i]=tmp[i];
		b[k].title[i]=tmp[i];
		b[k].title[++i]=0;

		for(j=0;b[k].author[j]=tmp[i];i++,j++);
		b[k++].tag=0;
	}
	return k;
}

void read_title(char *tmp,char* tmp_title){
	int i=7,j=0;			
	while((tmp_title[j++]=tmp[i++])!=34);
	tmp_title[j++]='\0';
}

void SHELVE(int k){
	char tmp[size];
	sort(r,r+k,cmp);
	for(int i=0;i<k;i++){
		
		int j=0;
		while(b[j].tag!=2)j++;
		b[j].tag=0;
		
		j--;
		while(j>=0 && b[j].tag!=0)j--;
		
		if(j<0){
			printf("Put %s first\n",r[i].title);
		}else{
			printf("Put %s after %s\n",r[i].title,b[j].title);
		}
	}
	
}

void BORROW(char *p){
	int i=0;
	while(strcmp(p,b[i].title)!=0)i++;
	b[i].tag=1;
}

void RETURN(char *p,int k){
	int i=0;
	while(strcmp(p,b[i].title))i++;
	b[i].tag=2;
	strcpy(r[k].author,b[i].author);
	strcpy(r[k].title,b[i].title);
}

void borrowed_and_returned(){
	char tmp[200];
	char tmp_title[size];
	int i=0,j,k;
	while(gets(tmp) && tmp[0]!='E'){
		if(strcmp(tmp,"SHELVE")==0){
			SHELVE(k);
			k=0;
			printf("END\n");
		}
		else{
			read_title(tmp,tmp_title);
			if(tmp[0]=='B')BORROW(tmp_title);
			else {
				RETURN(tmp_title,k);
				k++;
			}

		}
	}
	
}
int main()
{
int num=read();
sort(b,b+num,cmp);
borrowed_and_returned();
getchar();getchar();
return 0;
}
