#include<stdlib.h>
#include<stdio.h>
#include<string.h>
const int N=2100;
int n,map[N],str1[N],str2[N],tmpsmal[N],tmpbig[N],tmp[N],ntrue;
char str0[N];
bool first;


int cmp(const void*a,const void*b){
	return *((const int *) a) - *((const int *) b);
}

void print(int beg,int end,int*p){
	for(int i=beg;i<=end;i++){
		printf("%d  ",p[i]);
	}
	printf("\n");
}

void totrue(int *p){
	int num=p[0];
	for(int i=1;i<=num;i++){
		if(map[p[i]]!=2){map[p[i]]=2;ntrue++;}
	}
}

void trueto(){
	int num=map[0];
	for(int i=1;i<=num;i++){
		if(map[i]==0){
			map[i]=2;
			ntrue++;
		}
	}
}

void addsmalfirst(int* p){
	
	int num=p[0],j=0;
	for(int i=1;i<=num;i++){
		if(map[p[i]]==0){
			map[p[i]]=-1;
			tmpsmal[++j]=p[i];
		}
	}
	tmpsmal[0]=j;
}
void addbigfirst(int* p){
	int num=p[0],j=0;
	for(int i=1;i<=num;i++){
		if(map[p[i]]==0){
			map[p[i]]=1;
			tmpbig[++j]=p[i];			
		}
	}
	tmpbig[0]=j;
}

void addsmal(int* p){
	int numstr=p[0];
	int numsmal=tmpsmal[0];
	int i=1,j=1,k=1;
	qsort(p+1,numstr,sizeof(int),cmp);
	qsort(tmpsmal+1,numsmal,sizeof(int),cmp);
	
	for(;i<=numstr && j<=numsmal;){
		
		if(p[i] ==tmpsmal[j]) tmpsmal[k++]=tmpsmal[j++],i++;
		else if(p[i] < tmpsmal[j]) map[p[i++]]=2;
		else map[tmpsmal[j++]]=2;
	}
	while(j<=numsmal)map[tmpsmal[j++]]=2;
	while(i<=numstr) map[p[i++]]=2;

	tmpsmal[0]=k-1;
}
void addbig(int* p){
	int numstr=p[0];
	int numbig=tmpbig[0];
	int i=1,j=1,k=1;
	
	qsort(p+1,numstr,sizeof(int),cmp);
	qsort(tmpbig+1,numbig,sizeof(int),cmp);

	for(;i<=numstr && j<=numbig;){

		if(p[i] ==tmpbig[j]) tmpbig[k++]=tmpbig[j++],i++;
		else if(p[i] < tmpbig[j])map[p[i++]]=2;
		else map[tmpbig[j++]]=2;
	}

	while(j<=numbig)map[tmpbig[j++]]=2;
	while(i<=numstr)map[p[i++]]=2;
	tmpbig[0]=k-1;
}
int find(){
	int num=map[0];
	for(int i=1;i<=num;i++)if(map[i]!=2)return i;
}

void fixtmp(int* p){
	int num=p[0];

	int i=1,j=1;
	for(;j<=num;j++){
		if(map[p[j]]!=2)p[i++]=p[j];
	}
	p[0]=i-1;
}

int fun(char c){
	if(c=='='){
		totrue(str1),totrue(str2);
	}
	else if(c=='<'){
		if(first){
			first=false,addsmalfirst(str1),addbigfirst(str2),trueto();
		}
		else{
			addsmal(str1),addbig(str2);
		}
	}
	else{
		if(first){
			first=false,addsmalfirst(str2),addbigfirst(str1),trueto();
		}
		else{
			addsmal(str2),addbig(str1);
		}
	}

	fixtmp(tmpsmal),fixtmp(tmpbig);

	if(tmpsmal[0]==1 && tmpbig[0]==0)return tmpsmal[1];
	if(tmpsmal[0]==0 && tmpbig[0]==1)return tmpbig[1];
	if(ntrue+1==n)return find();

	return 0;
}

int main()
{
	int m,num;
	while(scanf("%d%d",&n,&m)!=EOF){
		int ans=0;
		ntrue=0;
		first=true;
		memset(map,0,(n+1)*sizeof(int));
		map[0]=n;
		while(m--){
			scanf("%d",&num);
			str1[0]=num;
			for(int i=1;i<=num;i++){
				scanf("%d",&str1[i]);
			}
			str2[0]=num;
			for(int i=1;i<=num;i++){
				scanf("%d",&str2[i]);
			}
			scanf("%s",str0);
			if(ans)continue;
			ans=fun(str0[0]);
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
