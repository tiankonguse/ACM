#include<stdio.h>
#include<string.h>
void mysort(int Num,int* List){
    int i,j,_max;
    for(i = 0; i < Num; i++){
        _max=i;
        for(j = i + 1; j < Num; j++){
            if(List[j]>List[_max]){
                _max = j;
            }
        }
        if(_max ^ i){
            List[_max]^=List[i]^=List[_max]^=List[i];
        }
    }
}

int main() {
    bool cow[222];
    int str[222];
    int m,s,c,_min,_max,tmp;
    int i,j,num,ans;
    while(~scanf("%d%d%d",&m,&s,&c)) {
        memset(cow,false,sizeof(cow));
        _min=s;
        _max=1;
        while(c--) {
            scanf("%d",&tmp);
            cow[tmp]=true;
            if(_min > tmp)_min = tmp;
            if(_max < tmp)_max = tmp;
        }
        ans=_max-_min+1;
        num=0;
        for(i = _min; i < _max;) {
            while(cow[i] && i <= _max)i++;
            if(i > _max)break;
            tmp=0;
            while(!cow[i])tmp++,i++;
            str[num++]=tmp;
        }
        mysort(num,str);
        m--;
        for(i=0;i<m && i<num;i++){
            ans-=str[i];
        }
        printf("%d\n",ans);

    }
    return 0;
}
