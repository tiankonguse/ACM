#include<iostream>
#include<cstdio>
#include<set>
#include<cstring>
#include<cstdlib>
#include<functional>
#include<functional>
#include<algorithm>
using namespace std;

int str[202][201][201];

int array[201];

int find(int l,int r, int min){

    if(str[min][l][r] != -1)return str[min][l][r];

    if(l > r) return str[min][l][r] = 0;

    if(l == r){
        if(array[l] > min)return str[min][l][r] = 1;
        return str[min][l][r] = 0;
    }

    if( array[l] == array[r]){

        str[min][l][r] =find(l+1,r-1,min);

        if(array[l] > min){
            str[min][l][r] =max(find(l+1,r-1,array[l]) + 2, str[min][l][r]);
        }

        return str[min][l][r];
    }else{
        return str[min][l][r] = max(find(l+1,r,min),find(l,r-1,min));
    }
}
/*
1
8
50 250 51 52 52 51 250 50

*/
int main(){
    int t, n, i;
    scanf("%d",&t);
     while(t--){
         memset(str,-1,sizeof(str));
         scanf("%d",&n);
         for(i=0;i<n;i++){
            scanf("%d",&array[i]);
            array[i] -= 49;
         }
         find(0,n-1,0);
         if(str[0][0][n-1] == 0)str[0][0][n-1] = 1;
         printf("%d\n",str[0][0][n-1]);
     }

    return 0;
}
