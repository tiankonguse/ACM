#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

// 0x3f3f3f3f = 1061109567 (recommended)
const int inf = 0x3f3f3f3f;
// 0x3FFFFFFFFFFFFFFFLL = 4611686018427387903 (recommended)
const LL Inf = 0x3FFFFFFFFFFFFFFFLL;
// 10^9 + 7
const int mod = 1000000007;

#define memsetMin(arr) memset(arr, 0xc0, sizeof(arr))
#define memsetMax(arr) memset(arr, 0x3f, sizeof(arr))

//memset
//memset(dpMin, 0x3f, sizeof(dpMin)); // inf
//memset(dpMax, 0xc0, sizeof(dpMax)); // -inf


char str[2222222];
int strM[2222222];
int strN[2222222];
int strS[2222222];
char ans[2222222];

int countPosOne[2222222];
map<int, int> countOnePos;
int n,m;

void tryCase(int pos, int* str1, int& p1, int* str2, int& p2){ // p1 > p2
    //优先尝试低位填充一个 1

    int needOne = p1 - p2 + 1;
    int oneCount = countPosOne[pos] + needOne;

    if(countOnePos.count(oneCount) == 0){
        // 特殊策略不满足，走正常贪心策略
        str1[--p1] = 1;
        return ;
    }


    int endPos = countOnePos[oneCount];
    int zeroNum = (endPos - pos) - needOne;
    if(zeroNum > p2 - 1) {
        // 特殊策略不满足，走正常贪心策略
        str1[--p1] = 1;
        return ;
    }


    //此时满足特殊策略
    str2[--p2] = 1; //低位给一个 1


//    while(pos <= endPos){
//        if(str[pos] == '1'){
//            str1[--p1] = 1;
//        }else{
//            str2[--p2] = 0;
//        }
//        pos++;
//    }
//    pos--; //因为循环会加 1，所以需要减去 1
}

int main() {
    int t, l;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d",&n,&m);
        scanf("%s", str);
        if(n < m){
            swap(n, m);
        }

        int pm = m, pn = n;
        for(int i=0;i<=n+m+2;i++){
            strS[i] = strM[i] = strN[i] = 0;
        }
        countOnePos.clear();

        int oneNum = 0;
        for(int i=0;i<n+m;i++){
            if(str[i] == '1'){
                oneNum++;
                countOnePos[oneNum] = i;
            }
            countPosOne[i] = oneNum;
//            printf("%d ", countPosOne[i]);
        }
//        printf("\n");
//        for(auto& p: countOnePos){
//            printf("%d:%d\n",p.first,p.second);
//        }


        for(int i=0;i<n+m;i++){
//            printf("%d: pn=%d pm=%d\n", i, pn, pm);
            if(pm == 0){
                strN[--pn] = str[i] - '0';
            }else if(pn == 0){
                strM[--pm] = str[i] - '0';
            }else if(pm == pn){
                strN[--pn] = str[i] - '0';
            }else if(str[i] == '1'){
                if(pm >= pn){
                    tryCase(i, strM, pm, strN, pn);
                }else{
                    tryCase(i, strN, pn, strM, pm);
                }
            }else{
                if(pm < pn){
                    strM[--pm] = 0;
                }else{
                    strN[--pn] = 0;
                }
            }
        }
//
//        printf("n-m: in\n");
//        for(int i=0;i<n;i++){
//            printf("%d", strN[i]);
//        }
//        printf("\n");
//        for(int i=0;i<m;i++){
//            printf("%d", strM[i]);
//        }
//        printf("\n");
//        printf("n-m: out\n");
//        for(int i=n-1;i>=0;i--){
//            printf("%d", strN[i]);
//        }
//        printf("\n");
//        for(int i=m-1;i>=0;i--){
//            printf("%d", strM[i]);
//        }
//        printf("\n");

        int S = 0;
        int i = 1;
        for(i=0;i<=n+1;i++){
            S += strN[i] + strM[i];
            strS[i] = S % 2;
            S = S / 2;
        }

        while(i > 0 && strS[i] == 0){
            i--;
        }
        int ansPos = 0;
        while(i >= 0){
            ans[ansPos++] = '0' + strS[i--];
        }
        ans[ansPos] = '\0';
        printf("%s\n", ans);
    }

    return 0;
}

/*
6
4 3
1000101
2 2
1111
1 1
00
2 3
10111
6 4
1001111010
3 3
000000
*/

