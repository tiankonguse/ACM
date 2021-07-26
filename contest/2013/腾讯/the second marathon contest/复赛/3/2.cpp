/**************************************************************************
 **      File Name: 1.cpp
 **      Author: tiankonguse
 **      Mail: shen10000shen@gmail.com
 **      Created Time: 2013/3/31 18:27:12
/**************************************************************************/

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

bool cmp(const int& a, const int&b){
    return a<b;
}

char _str[222][20]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty","twentyone","twentytwo","twentythree","twentyfour","twentyfive","twentysix","twentyseven","twentyeight","twentynine","thirty","thirtyone","thirtytwo","thirtythree","thirtyfour","thirtyfive","thirtysix","thirtyseven","thirtyeight","thirtynine","forty","fortyone","fortytwo","fortythree","fortyfour","fortyfive","fortysix","fortyseven","fortyeight","fortynine","fifty","fiftyone","fiftytwo","fiftythree","fiftyfour","fiftyfive","fiftysix","fiftyseven","fiftyeight","fiftynine","sixty","sixtyone","sixtytwo","sixtythree","sixtyfour","sixtyfive","sixtysix","sixtyseven","sixtyeight","sixtynine","seventy","seventyone","seventytwo","seventythree","seventyfour","seventyfive","seventysix","seventyseven","seventyeight","seventynine","eighty","eightyone","eightytwo","eightythree","eightyfour","eightyfive","eightysix","eightyseven","eightyeight","eightynine","ninety","ninetyone","ninetytwo","ninetythree","ninetyfour","ninetyfive","ninetysix","ninetyseven","ninetyeight","ninetynine","onegoogol","twogoogol","threegoogol","fourgoogol","fivegoogol","sixgoogol","sevengoogol","eightgoogol","ninegoogol","tengoogol","elevengoogol","twelvegoogol","thirteengoogol","fourteengoogol","fifteengoogol","sixteengoogol","seventeengoogol","eighteengoogol","nineteengoogol","twentygoogol","twentyonegoogol","twentytwogoogol","twentythreegoogol","twentyfourgoogol","twentyfivegoogol","twentysixgoogol","twentysevengoogol","twentyeightgoogol","twentyninegoogol","thirtygoogol","thirtyonegoogol","thirtytwogoogol","thirtythreegoogol","thirtyfourgoogol","thirtyfivegoogol","thirtysixgoogol","thirtysevengoogol","thirtyeightgoogol","thirtyninegoogol","fortygoogol","fortyonegoogol","fortytwogoogol","fortythreegoogol","fortyfourgoogol","fortyfivegoogol","fortysixgoogol","fortysevengoogol","fortyeightgoogol","fortyninegoogol","fiftygoogol","fiftyonegoogol","fiftytwogoogol","fiftythreegoogol","fiftyfourgoogol","fiftyfivegoogol","fiftysixgoogol","fiftysevengoogol","fiftyeightgoogol","fiftyninegoogol","sixtygoogol","sixtyonegoogol","sixtytwogoogol","sixtythreegoogol","sixtyfourgoogol","sixtyfivegoogol","sixtysixgoogol","sixtysevengoogol","sixtyeightgoogol","sixtyninegoogol","seventygoogol","seventyonegoogol","seventytwogoogol","seventythreegoogol","seventyfourgoogol","seventyfivegoogol","seventysixgoogol","seventysevengoogol","seventyeightgoogol","seventyninegoogol","eightygoogol","eightyonegoogol","eightytwogoogol","eightythreegoogol","eightyfourgoogol","eightyfivegoogol","eightysixgoogol","eightysevengoogol","eightyeightgoogol","eightyninegoogol","ninetygoogol","ninetyonegoogol","ninetytwogoogol","ninetythreegoogol","ninetyfourgoogol","ninetyfivegoogol","ninetysixgoogol","ninetysevengoogol","ninetyeightgoogol","ninetyninegoogol"};
vector<int>str[20];
char ss[1000] ="0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
int main(){

    int i,_max=18,len,_min=3,j,t,n,m;
    for(i=0;i<199;i++){
        len = strlen(_str[i]);
        str[len].push_back(i);
    }
    for(i=_min;i<=_max;i++){
        sort(str[i].begin(),str[i].end(),cmp);
    }

//    printf("%s",_str[100]);

//    for(i=_min;i<=_max;i++){
//        len = str[i].size();
//        printf("%d-->",i);
//        for(j=0;j<len;j++){
//            printf("%d ",str[i][j]);
//        }
//        puts("");
//    }

    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d%d",&n,&m);
        if(str[n].size() < m){
            printf("Case #%d: -1\n",i);
        }else{
            m--;
            if(str[n][m]>=100){
                printf("Case #%d: %d%s\n",i,str[n][m]-99,ss);
            }else{
                printf("Case #%d: %d\n",i,str[n][m]);
            }
        }
    }

    return 0;
}
