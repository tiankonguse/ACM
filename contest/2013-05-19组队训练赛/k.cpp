
#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int n = 114;
char in[55555];
bool have[55555];
char str[][5]={
    "H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn","Fl","Lv","La","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu","Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr","zzz"};
int len[200];
int _map[256];


void toLow(char *p){
    while(*p){
        if(*p<='Z' && *p >= 'A')*p = *p - 'A' + 'a';
        p++;
    }
}

int cmp(const void *a,const void *b){
    return strcmp((const char*)a,(const char*)b);
}

bool ok(char *a, char *b){
    while(*a && *b ){
        if(*a != *b)return false;
        a++,b++;
    }
    if(*b)return false;
    return true;
}

bool dfs(char *p,int lev){
    if(!*p)return true;
//    printf("--%d  %s\n",lev,p);
    if(_map[*p] == -1)return false;
    if(have[lev] == false)return false;

    for(int i=_map[*p];i<n;i++){
        if(*p < str[i][0])break;
        if(ok(p,str[i])){
//                puts("--");
            if(dfs(p+len[i],lev+len[i]))return true;
        }
    }
    return have[lev]=false;
}

int _find(char c){
    for(int i=0;i<n;i++){
        if(str[i][0]==c)return i;
    }
    return -1;
}

int main(){
    int i,cas;
    for(i=0;i<n;i++){
        toLow(str[i]);
    }



    qsort(str,n,sizeof(str[0]),cmp);
    for(i=0;i<n;i++){
//            printf("%d  %s\n",i,str[i]);
        len[i] = strlen(str[i]);
    }

    for(i='a';i<='z';i++){
            _map[i] = _find(i);
    }

    scanf("%d",&cas);
    while(cas--){
            scanf("%s",in);
            toLow(in);
            memset(have,true,sizeof(have));
            printf("%s\n",dfs(in,0)?"YES":"NO");
    }



    return 0;
}
