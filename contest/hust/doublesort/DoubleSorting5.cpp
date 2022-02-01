#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long LL;

int str[2][10];
int n;
int ans;

int getNum() {
    int ans = 0;
    int i,j,top,bottom;
    for(i=1; i<=n; i++) {
        for(j=i+1; j<=n; j++) {
            for(top=0; top<2; top++) {
                for(bottom=0; bottom<2; bottom++) {
                    if(str[top][i] > str[bottom][j]) {
                        ans++;
                    }
                }
            }
        }
    }
    return ans;
}

int main(int argc, char* argv[]) {
    while(~scanf("%d",&n)) {
        for(int i=1; i<=n; i++) {
            scanf("%d%d",&str[0][i],&str[1][i]);
            if(str[0][i]>str[1][i])swap(str[0][i],str[1][i]);
        }
        int num = getNum();
        if(num == 0){
        	ans = 0;
        }else{
        	ans = (num + 1)/3 + 1;
        }
        printf("%d\n",ans);
        break;
    }

    return 0;
}

/*
8
8 8
7 7
6 6
5 5
4 4
3 3
2 2
1 1

7
7 7
6 6
5 5
4 4
3 3
2 2
1 1

6
6 6
5 5
4 4
3 3
2 2
1 1

5
5 5
4 4
3 3
2 2
1 1

4
4 4
3 3
2 2
1 1

5
1 5
3 4
2 5
2 3
1 4

8
8 3
4 2
6 4
3 5
5 8
7 1
2 6
1 7


0:1534252314
1:1523452314
2:1523243514
3:1523241345
4:1523123445
5:1512233445
6:1125233445
7:1122353445
8:1122334545
9:1122334455

0:1534252314
1:1524352314
2:1245352314
3:1245233514
4:1245231345
5:1224351345
6:1224133545
7:1224133455
8:1212343455
9:1212334455
10:1122334455


*/
