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
int pos[250010];
int len[250010];
char* str[250010];
char*pstr;
char _str[25000000];
char ans[250100];
char op[250010];
int n;

//字符串的总长度
int nowlen;

void findChar(int left,int right,int lev,int& p){
    //left，right是当前在插入lev字符串后查询的左右边界，p是查询的字符串应该在ans中填充的起始位置
    int begin,end,i;

//    scanf("%d",&tmp);
    //非法的操作，结束递归
    if(lev<0 || left<0 || left > right || right>=nowlen)return ;


    //now 代表的当前插入的字符串，求出now在插入后的左右边界
    int nowleft = pos[lev],nowright = pos[lev] + len[lev]-1;

//    printf("\n--->left=%d  right=%d  p=%d nowleft=%d nowright=%d\n",left,right,p,nowleft,nowright);

    if(right < nowleft){
        //如果查询的串在now之后，now不影响查询的串和p
        findChar(left, right, lev-1, p);
    }else if(left > nowright){
        //如果查询的串在now之前，则查询的串应该左移len[lev]个单位,不影响p
        findChar(left - len[lev], right - len[lev], lev-1,p);
    }else{
        //查询的串与当前插入的串有交集
        if(right <= nowright){
                if(left >= nowleft){
                    //当前查询的串完全在插入的串中

                    //得到需要的字符串的起始位置
                    begin  = left-nowleft;
                    end    = right - nowleft + 1;

                    for(i=begin;i<end;i++){
                        ans[p++] = str[lev][i];
                    }
                }else{
                    //当前插入的串的左部是查询的串的右部。

                    //先查询不在插入的串的部分，,不影响p
                    findChar(left, nowleft-1, lev-1, p);


                    //得到需要的字符串的起始位置
                    begin  = 0;
                    end    = right - nowleft + 1;

                    for(i=begin;i<end;i++){
                        ans[p++] = str[lev][i];
                    }

                }
        }else{
            if(left>=nowleft){
                //当前插入的串的右部是查询的串的左部。

                //需要先得到需要的字符串的起始位置
                begin  = left - nowleft;
                end    = nowright - nowleft + 1;

                for(i=begin;i<end;i++){
                    ans[p++] = str[lev][i];
                }

                //先查询不在插入的串的部分，查询的左边界变为nowleft ，查询的右边界需要左移len[lev]个单位,不影响p
                findChar(nowleft, right-len[lev], lev-1, p);
            }else{
                //当前插入的串完全在查询的串中

                //查询左半部
                findChar(left,nowleft-1,lev-1,p);


                //需要先得到需要的字符串的起始位置
                begin  = 0;
                end    = len[lev];

                for(i=begin;i<end;i++){
                    ans[p++] = str[lev][i];
                }

                //查询右半部，查询的左边界变为nowleft ，查询的右边界需要左移len[lev]个单位,不影响p
                findChar(nowleft, right-len[lev], lev-1, p);
            }

        }
    }
}

void output(int left,int right){
//    printf("%02d %02d -->",left,right);
    int w;
    if(left<=right){
//        if(right>nowlen)right=nowlen-1;
//        if(left>nowlen)left=nowlen;

        w = 0;
        findChar(left,right,n-1,w);
        ans[w]='\0';
        puts(ans);
    }else{
//        if(left>nowlen)left=nowlen-1;
//        if(right>nowlen)right=nowlen;


        w = 0;
        findChar(right,left,n-1,w);
        ans[w]='\0';

        //反转
//        left = 0;
//        right = w-1;
//        while(left < right){
//            ans[left]^=ans[right],ans[right]^=ans[left],ans[left]^=ans[right];
//            left++,right--;
//        }

        puts(ans);
    }
}

int main() {


    int left,right,i;

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
                len[n] = strlen(pstr);
                nowlen += len[n];
                str[n] = pstr;
                pstr = pstr + len[n] + 1;
                n++;
            }else{
                scanf("%d%d",&left,&right);
                output(left,right);
            }
        }

//        if(op[0] == 'E'){
//            break;
//        }

//        strcpy(_str,op);
            while(1){
                scanf("%d%d",&left,&right);
                output(left,right);
                puts("---");
            }

//        output(3,4);
//        for(int i=0;i<nowlen;i++){
//            for(int j=i;j<nowlen;j++){
//                output(i,j);
//            }
//            puts("");
//        }
//break;
    }


    return 0;
}
