#include<stdio.h>
#include<string.h>
const int N=1000010;
const int M=80000;
const int LEN=1000;
bool map[N];
int str[M];
int str2[50];
int len;
int prame()
{
    memset(map,true,sizeof(map));
    int k=0;
    str[k++]=2;
    for(int i=3;i<N;i+=2)
        if(map[i])
        {
            str[k++]=i;
			int  s=i+i;		
            for(int j=i>LEN?N:i*i;j<N;j+=s)
                map[j]=false;
        }
return k;
}

bool mod(int p){
	int left=0;
	for(int j=0;j<len;j++)
	{
		left=left*LEN+str2[j];
		left%=p;
	}
	//printf("%d  %d\n",p,left);
return left;	
}

int main()
{
	prame();
	int n,h,i,j,ans;
	char str1[111];
	while(scanf("%s %d",str1,&n),n)
	{
		
		len=strlen(str1);
		h=len%3;
		j=i=0;
		if(h==1){
			str2[j]=str1[i++]-'0';

			j++;
		}
		else if(h==2){
			str2[j++]=(str1[i]-'0')*10 + str1[i+1]-'0';
			i+=2;	
		}

		for(;str1[i];j++){
			str2[j]=0;
			for(int k=0;k<3;k++){
				str2[j]=str2[j]*10+str1[i++]-'0';
			}
		}
		len=j;

	//	for(i=0;i<len;i++){
	//		printf("%d ",str2[i]);
	//	}
	//	printf("\n");
		
		ans=0;
		for(i=0;str[i]<=n;i++){
			if(mod(str[i])==0){
				ans=str[i];
				break;
			}
		}
		if(ans) printf("BAD %d\n",ans);  
        else printf("GOOD\n");
	}
	return 0;	
}
