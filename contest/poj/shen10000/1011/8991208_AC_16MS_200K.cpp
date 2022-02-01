#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 55
int stick[N],t[N],a;

// 深搜（ 还需的长度, 之后的最长长度, 倒数第几根, 剩余棍子总长）;
//返回 0 为深搜失败, 1 为成功.
bool dfs( int len, int k, int rem, int left) {
    if( rem==0 )   return 1;
    if( len==0 )   return (dfs(a,a,rem-1,left));
   	if( k>=N ) k=N-1;
    if( k>len )    k=len;

    if( t[k]==0 )while( k>0 && t[--k]==0 );
    if( k==0 )	return 0;
    
    if( len==a ) {
        t[k]--;
        if( dfs(len-k,k,rem,left)) return 1;
        t[k]++;
        return 0;
    }
    
    if( k<=len ) {
        for( ; k>0 && left>=len ; left-= t[k]*k,k--)
			if( t[k]>0 ) {
				t[k]--;
                if( dfs(len-k,k,rem,left)) return 1;
				t[k]++;
			}
		return 0;
    }/* Core above */
}

int main()
{
    int i,k,n,sum;
    while( scanf("%d",&n), n ) {
        memset( stick, 0, N*sizeof(int) );
        for( sum=k=0; n--; ) {
            scanf("%d",&i);
            stick[i]++;
            if( i>k ) k=i;
            sum +=i;
        }
		for( a=k; a<=sum; a++ )
            if( sum%a==0 ) {
                for( i=0; i<N; i++)
                    t[i]=stick[i];
				if( dfs(a,a,sum/a,sum))
                    break;
            }
		printf("%d\n",a);
    }
    system("PAUSE");
    return 0;
}


