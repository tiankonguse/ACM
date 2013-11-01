/*************************************************************************
    > File Name: 0.cpp
    > Author: tiankonguse
    > Mail: i@tiankonguse.com
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
const int N=6000;
char str1[N];
int n;
char str2[N];
int str3[N];//实际 pos
char ans[N];


int main() {
    while(~scanf("%d",&n)) {
        scanf("%s",str1);
        int j=0;
        for(int i=0; str1[i]; i++) {
            if(str1[i] != '=') {
                str2[j] = str1[i];
                str3[j] = i;
                j++;
            }
        }
        str2[j] = '\0';
        char preVal;
        int prePos;
        int pos,i;
        memset(ans,'\0',sizeof(ans));
//        printf("j=%d %s\n",j,str2);
        for(i=0; str2[i]; i++) {
            if(str2[i] == '>') {
                if(i) {
                    if(str2[i-1] == '<') {
                        preVal = ans[ str3[i] ] = 'a'+ n - 1;
                    } else {
                        preVal = ans[ str3[i] ] = preVal - 1;
                        if(preVal  == 'a') {
                            break;
                        }
                    }
                } else {
                    preVal = ans[ str3[i] ] = 'a' + n - 1;
                    if(preVal  == 'a') {
                        break;
                    }
                }
            } else {
                //<
                if(i) {
                    if(str2[i-1] == '>') {
                        preVal = ans[ str3[i] ] = 'a';
                    } else {
                        preVal = ans[ str3[i] ] = preVal + 1;
                        if(preVal  >= 'a' + n - 1) {
                            break;
                        }
                    }
                } else {
                    preVal = ans[ str3[i] ] = 'a';
                    if(preVal  >= 'a' + n - 1) {
                        break;
                    }
                }
            }
        }
//        printf("i=%d %s\n",i,str2);
        if(j && str2[i]) {
            printf("-1\n");
        } else {
//            printf("here\n");
            if(j == 0) {
                ans[0] = 'a';
            } else {
                if(str2[i-1] == '>') {
                    ans[ str3[i-1] + 1]  = 'a';
                } else {
                    ans[ str3[i-1] + 1]  = 'a' + n - 1;
                }
            }
            for(i=0;str1[i];i++){
                if(str1[i] == '='){
                    if(ans[i] == '\0' && ans[i+1] == '\0'){
                        continue;
                    }else if(ans[i] == '\0' && ans[i+1] != '\0'){
                        ans[i] = ans[i+1];
                    }else if(ans[i] != '\0' && ans[i+1] == '\0'){
                        ans[i+1] = ans[i];
                    }
                }
            }
            int l = i;
            for(i--;i>=0;i--){
                if(str1[i] == '='){
                    if(ans[i] == '\0' && ans[i+1] == '\0'){
                        continue;
                    }else if(ans[i] == '\0' && ans[i+1] != '\0'){
                        ans[i] = ans[i+1];
                    }else if(ans[i] != '\0' && ans[i+1] == '\0'){
                        ans[i+1] = ans[i];
                    }
                }
            }
            ans[l+1] = '\0';
//            for(i=0;i<)
            printf("%s\n",ans);
        }
    }
    return 0;
}
