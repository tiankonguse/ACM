/*************************************************************************
    > File Name: 4.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/1 19:37:09
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
int pos[1001];
int len[1001];
char* str[1001];
char*pstr;
char _str[25000000];
char ans[250100];
int n;
    int nowlen;
void findChar(int left,int right,int lev,int& p){

    int tmp,t;

//    scanf("%d",&tmp);
    if(lev<0 || left<0 || left > right || right>=nowlen)return ;

    int nowleft = pos[lev],nowright = pos[lev] + len[lev]-1;
//    printf("\n--->left=%d  right=%d  p=%d nowleft=%d nowright=%d\n",left,right,p,nowleft,nowright);
    if(right < nowleft){
        findChar(left,right,lev-1,p);
    }else if(left > nowright){
        findChar(left - len[lev],right - len[lev],lev-1,p);
    }else{
        if(right <= nowright){
                if(left >= nowleft){
//                    printf("===%s\n",str[lev]);
                    tmp = right - left +1;
                    for(int i=left-nowleft,j=0;j<tmp;i++,j++){
                        ans[p++] = str[lev][i];
//                        putchar(str[lev][i]);
                    }
                }else{
                    findChar(left,nowleft-1,lev-1,p);
                    t = nowleft-1 - left;
                    tmp = right - nowleft +1;
                    for(int i=0;i<tmp;i++){
                        ans[p++] = str[lev][i];
//                        putchar(str[lev][i]);
                    }

                }
        }else{
            if(left>=nowleft){
                for(int i=left-nowleft;str[lev][i];i++){
                    ans[p++] =  str[lev][i];
//                    putchar(str[lev][i]);
                }
                findChar(nowright-len[lev]+1,right-len[lev],lev-1,p);
            }else{
                findChar(left,nowleft-1,lev-1,p);

                for(int i=0;str[lev][i];i++){
                    ans[p++] =  str[lev][i];
                }

//                printf("%s",str[lev]);

                findChar(nowright-len[lev]+1,right-len[lev],lev-1,p);
            }

        }
    }
}

void output(int left,int right){
//    printf("%02d %02d -->",left,right);
    int w;
    if(left<=right){
        if(right>nowlen)right=nowlen-1;
        if(left>nowlen)left=nowlen;

        w = 0;
        findChar(left,right,n-1,w);
        ans[w]='\0';
        puts(ans);
    }else{
        if(left>nowlen)left=nowlen-1;
        if(right>nowlen)right=nowlen;


        w = 0;
        findChar(right,left,n-1,w);
        ans[w]='\0';
        left = 0;
        right = w-1;
        while(left < right){
            ans[left]^=ans[right],ans[right]^=ans[left],ans[left]^=ans[right];
            left++,right--;
        }
        puts(ans);
    }
}

int main() {

    char op[10];
    int left,right;



    while(~scanf("%s",_str)){
        len[0] = strlen(_str);
        pos[0] = 0;
        str[0] = _str;
        n = 1;
        nowlen = len[0];



        pstr = _str + len[0] + 1;

        while(scanf("%s",op),op[0]!='E'){
            if(op[0]=='I'){
                scanf("%s%d",pstr,&pos[n]);
                if(nowlen < pos[n]){
                    pos[n] = nowlen;
                }
                nowlen += pos[n];

                len[n] = strlen(pstr);
                str[n] = pstr;
                pstr = pstr + len[n] + 1;
                n++;
            }else{
                scanf("%d%d",&left,&right);
                output(left,right);
            }
        }
//
//        for(int i=0;i<=15;i++){
//            for(int j=0;j<=15;j++){
//                output(i,j);
//            }
//        }
    }


    return 0;
}
