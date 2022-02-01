#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define lne 10000
int a[lne],c[lne];
int n;
bool input(){
	if(scanf("%d",&a[n=0])==1&&a[0]!=-1){
		for(n=1;scanf("%d",&a[n])==1&&a[n]!=-1;n++);
		return true;
	}
	else return false;
}
int binary_search(int c[],int len,int v){
	int left=1,right=len,mid=left+(right-left)/2;
	while(left<=right){
		if(v<c[mid])     left=mid+1;
		else if(v>c[mid])   right=mid-1;
		else return mid;
		mid=left+(right-left)/2;
	}
	return left;
}
int LIS(){
	int i,j,len=1;
	c[0]=-1;  c[1]=a[0];
	for(i=1;i<n;i++){
		j=binary_search(c,len,a[i]);
		c[j]=a[i];
		if(j>len)    len=j;
	}
	return len;
}
int main(void){
	int ans,ncase=0;
	while(input()){
		ans=LIS();
		if(ncase)   putchar('\n');
		printf("Test #%d:\n  maximum possible interceptions: %d\n",++ncase,ans);
	}
	return 0;
}