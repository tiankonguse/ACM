#include<stdio.h>

int main(){
    int i,n,m;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&m);
        switch(m)
        {
        case 1:printf("1\n");break;
        case 2:printf("2 1 \n");break;    
        case 3:printf("3 1 2\n");break;    
        case 4:printf("2 1 4 3\n");break;    
        case 5:printf("3 1 4 5 2\n");break;    
        case 6:printf("4 1 6 3 2 5\n");break;    
        case 7:printf("5 1 3 4 2 6 7\n");break;    
        case 8:printf("3 1 7 5 2 6 8 4\n");break;    
        case 9:printf("7 1 8 6 2 9 4 5 3\n");break;    
        case 10:printf("9 1 8 5 2 4 7 6 3 10\n");break;    
        case 11:printf("5 1 6 4 2 10 11 7 3 8 9\n");break;    
        case 12:printf("7 1 4 9 2 11 10 8 3 6 5 12\n");break;    
        case 13:printf("4 1 13 11 2 10 6 7 3 5 12 9 8\n");break;         
        }   
    }
   return 0;
}