#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int str[105][3];
int m;
int k=1;
char map[105][250];
bool yes[105];
bool ok(){
	if(yes[k])return false;
	int i=0;
	while(map[k][i]==' '||map[k][i]=='\t')i++;
	if(map[k][i]=='E' && map[k][i+1]=='N' && map[k][i+2]=='D')return true;
	 yes[k]=true;
	return false;
}


void proq(){
	int p=0;	
	int i=0;
	char c;
	while(map[k][i]==' '||map[k][i]=='\t')i++;
	//接下来是Dcl的判断	
	if(map[k][i]=='D' && map[k][i+1]=='C' && map[k][i+2]=='L'){
		i+=3;
		while(map[k][i]==' '||map[k][i]=='\t')i++;
		c=map[k][i];
		if(str[c][0]==-1){
	//	printf("DCL  %c=0\n",c);
			str[c][0]=0;
			str[c][1]=0;
			k++;
			return ;
		}
		else if(str[c][0]==0){
		//	printf("ERROE %c  ",c);
			printf("%d 1\n",k);
			k++;
			return ;
		}
		else{
		//printf("now DCL  %c=0\n",c);
			str[c][0]=0;
			str[c][1]=0;
			k++;
			return ;
		}
	
	}
	//接下来是Inc的判断	
	if(map[k][i]=='I' && map[k][i+1]=='N' && map[k][i+2]=='C'){
		i+=3;
		while(map[k][i]==' '||map[k][i]=='\t')i++;
		c=map[k][i];
		
		if(str[c][0]==-1){
//			printf("error inc 2 %c ",c);
			printf("%d 2\n",k);
			k++;
			return ;
		}
		else{
			str[c][0]=1;
			str[c][1]++;
//			printf("%c++\n",c);
			k++;
			return ;
		}
	}
	//接下来是Dec的判断
	if(map[k][i]=='D' && map[k][i+1]=='E' && map[k][i+2]=='C'){
		i+=3;
		while(map[k][i]==' '||map[k][i]=='\t')i++;
		c=map[k][i];
		
		if(str[c][0]==-1){
//			printf("error dec 2 %c ",c);
			printf("%d 2\n",k);
			k++;
			return ;
		}
		else{
			str[c][0]=1;
			str[c][1]--;
//			printf("%c--\n",c);
			k++;
			return ;
		}
	}
	//接下来是goto的判断
	if(map[k][i]=='G' && map[k][i+1]=='O' && map[k][i+2]=='T' && map[k][i+3]=='O'){
		i+=4;
		while(map[k][i]==' '||map[k][i]=='\t')i++;
		
		
		if(map[k][i]>='0' && map[k][i]<='9'){
			while(map[k][i]!=' '){
				p=p*10+map[k][i]-'0';
				i++;
			}
//			printf("now goto %d \n",p);
			k=p;
			return ;					
		}
	
		c=map[k][i];
		i++;
		while(map[k][i]==' '||map[k][i]=='\t')i++;
		p=0;
		while(map[k][i]>='0' && map[k][i]<='9'){
			p=p*10+map[k][i]-'0';
			i++;
		}				
		
		if(str[c][0]==-1){
	//		printf("goto error %d ",k);
			printf("%d 2\n",k);
			k++;
			return ;			
		}
		else{
			if(str[c][1]>0){
   //		printf("now goto %d  yes\n",p);			
				k=p;
				return ;
			}
			else{
	//		printf("now no goto %d\n",str[c][1]);		
				k++;
				return ;
			}
		}

	}
	

		c=map[k][i];

		i++;
		while(map[k][i]==' '||map[k][i]=='\t')i++;
		if(map[k][i]!='='){
	//	printf("no use\n");
			k++;
			return;
		}
		
		if(str[c][0]==-1){
//			printf("error %c=  ",c);
			printf("%d 2\n",k);
			k++;
			return ;			
		}
		

			i++;
			while(map[k][i]==' '||map[k][i]=='\t')i++;
			p=0;
			while(map[k][i]>='0' && map[k][i]<='9'){
				p=p*10+map[k][i]-'0';
				i++;
			}
			str[c][0]=1;
			str[c][1]=p;
//			printf("now %c= %d\n ",c,p);
			k++;
			return ;			

}


void solver(){

	while(true){
		if(ok())break;
		proq();
	}

}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		k=1;
		memset(str,-1,sizeof(str));
		memset(yes,false,sizeof(yes));
		scanf("%d",&m);
		getchar();
		for(int j=1;j<=m;j++){
			gets(map[j]);
		}
		printf("%d\n",i);

		solver();
	}

return 0;
}