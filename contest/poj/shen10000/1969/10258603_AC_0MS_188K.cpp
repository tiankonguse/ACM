#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


int main()
{
__int64 n,m,a,b,left;
double S;
while(~scanf("%I64d",&n)) {
	m=(__int64)((sqrt(n*8.0+1)-1)/2);
	if(m&1){
		left=n-((m+1)>>1)*m;
	}else{
		left=n-(m>>1)*(m+1);
	}
//	printf("left=%I64d  m=%I64d \n",left,m);
	if(left==0){
		if(m&1){
			printf("TERM %I64d IS 1/%I64d\n",n,m);
		}else{
			printf("TERM %I64d IS %I64d/1\n",n,m);
		}
		
	}else{
		m++;
		if(m&1){
			m++;
			printf("TERM %I64d IS %I64d/%I64d\n",n,m-left,left);
		}else{
			m++;
			printf("TERM %I64d IS %I64d/%I64d\n",n,left,m-left);	
		}

	}
	
}
return 0;
}
