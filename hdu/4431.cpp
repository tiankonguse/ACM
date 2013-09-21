#include<stdio.h>
#include<string.h>

//四类牌的个数
const int  type_i[4]={9,9,9,7};
//四类牌的英文代号
const char type_c[4]={'m','s','p','c'};
//十三一
const int _13array[13][2]={{0,1},{0,9},{1,1},{1,9},{2,1},{2,9},{3,1},{3,2},{3,3},{3,4},{3,5},{3,6},{3,7}};
//用于将牌的代号转化为序号
int mymap[255];

//存起的牌，以及每一类的个数
int tiles[4][12],tiles_num[4];
//存赢的牌
bool have[4][10];

void init(){
	mymap['m']=0,mymap['s']=1,mymap['p']=2,mymap['c']=3;
    memset(tiles,0,sizeof(tiles));
    memset(have,0,sizeof(have));
    memset(tiles_num,0,sizeof(tiles_num));
}

void input(){
    char op[3];
    int n=13;
    while(n--){
        scanf("%s",op);
        tiles[mymap[op[1]]][op[0]-'0']++;
        tiles_num[mymap[op[1]]]++;
    }
}

void output(int n){
   if(n==0){
       printf("Nooten\n");
   }else{
       printf("%d",n);
       for(int i=0;i<4;i++){
           for(int j=1;j<=type_i[i];j++){
               if(have[i][j])printf(" %d%c",j,type_c[i]);
           }
       }
       puts("");
   }
}

bool is13(){
    bool _13double=false;
    for(int i=0;i<13;i++){
        switch(tiles[_13array[i][0]][_13array[i][1]]){
            case 1:break;
            case 2:
                if(_13double)return false;
                _13double=true;
            break;
            default:return false;break;
        }
    }
    if(!_13double)return false;

    return true;
}

bool is2(){
    bool _2one=false;
    for(int i=0;i<4;i++){
        for(int j=1;j<=type_i[i];j++){
            if(tiles[i][j]==1 || tiles[i][j]==4|| tiles[i][j]==3)return false;
        }
    }
    return true;
}

bool ok(int k){
    if(k==3){
        for(int i=1;i<=7;i++){
            if(tiles[k][i]%3!=0)return false;
        }
    }else{
        int now1=0,now2=tiles[k][1],now3=tiles[k][2];
        for(int i=1;i<=9;i++){
            now1=now2;
            now2=now3;
            now3=tiles[k][i+2];
            if(now1<0)return false;
            if(now1>=3)now1-=3;
            now2-=now1;
            now3-=now1;
        }
        if(now1<0 || now2<0 || now3<0)return false;
    }
return true;
}

bool normal(){

    for(int i=0;i<4;i++){
        if(tiles_num[i]%3!=0)return false;
    }

    for(int i=0;i<4;i++){
        if(!ok(i))return false;
    }

    return true;
}


bool isnormal(){
    for(int i=0;i<4;i++){
        for(int j=1;j<=type_i[i];j++){
            if(tiles[i][j]>=2){
                tiles[i][j]-=2;
                tiles_num[i]-=2;
                if(normal()){
                    tiles[i][j]+=2;
                    tiles_num[i]+=2;
                    return true;
                }
                tiles[i][j]+=2;
                tiles_num[i]+=2;
            }
        }
    }
    return false;
}


bool ok(){
    if(is13())return true;
    if(is2())return true;
    if(isnormal())return true;
    return false;
}

int main(){
	init();
    int cas,n;
    scanf("%d",&cas);
    while(cas--){
    	init();
        input();
        n=0;
        for(int i=0;i<4;i++){
            for(int j=1;j<=type_i[i];j++){
                tiles[i][j]+=1;
                tiles_num[i]+=1;
                if(tiles[i][j]<=4 && ok()){have[i][j]=true;n++;}
                tiles[i][j]-=1;
                tiles_num[i]-=1;
            }
        }
        output(n);
    }



    return 0;
}

/*
2
1s 2s 3s 2c 2c 2c 2p 3p 5m 6m 7m 1p 1p
1p 1p 2p 3p 4s 5s 6s 7c 7c 3s 3s 2m 2m

*/
