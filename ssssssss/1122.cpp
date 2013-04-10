#include<stdio.h>
#include<string.h>

bool IsChangeMin(char *first,char* second){
    return strcmp(first,second)<0;
}

void myswap(char *first,char *second){
    char tmp[100];
    strcpy(tmp,first);
    strcpy(first,second);
    strcpy(second,tmp);
}

void mysort(int Num,char List[][100]){

    int i,j,_Min;
    for(i = 0; i < Num; i++){
        _Min=i;
        for(j = i + 1; j < Num; j++){
            if(IsChangeMin(List[j] ,List[_Min])){
                _Min = j;
            }
        }
        if(_Min ^ i){
            myswap(List[_Min],List[i]);
        }
    }
}

int main(){
    char str[111][100];
    int n,i,m,cas=1;
    scanf("%d",&n);
    while(n--){
        for(m=0;scanf("%s",str[m]),str[m][0]^'#';m++);
        mysort(m,str);
        printf("Case %d:\n",cas++);
        for(i=0;i<m;i++){
            if(i)printf(" ");
            printf("%s",str[i]);
        }
        puts("\n");
    }


    return 0;
}
