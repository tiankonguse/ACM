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

int a[10],b[10];
int n;

void output() {
    static int num = 0;
    printf("%d:\n",num++);
    for(int i=0; i<n; i++) {
        printf("%d ",a[i]);
    }
    puts("");
    for(int i=0; i<n; i++) {
        printf("%d ",b[i]);
    }
    puts("");
    puts("");
}

bool little(int p, int now) {
    if(a[p] <= a[now] && b[p] <= b[now])  {// && a[p]+ 2 > a[now] && b[p] +2 > b[now]
        return false;
    }
    if(a[p] <= b[now] && b[p] <= a[now]) {//&& a[p] + 2 > b[now] && b[p] + 2 > a[now]
        return false;
    }

    if(a[p] > b[p]) {
        if(a[now] > b[now]) {
            swap(a[p], b[now]);
        } else {
            swap(a[p], a[now]);
        }
    } else {
        if(a[now] > b[now]) {
            swap(b[p], b[now]);
        } else {
            swap(b[p], a[now]);
        }
    }



    return true;
}

bool check() {
    static bool k = false;
    k =  !k;
    if(k) {
        for(int p=0,i=1; i<n; i++,p++) {
            if(little(p,i)) {
                return true;
            }
        }
    } else {
        for(int p=n-2,i=n-1; i; i--,p--) {
            if(little(p,i)) {
                return true;
            }
        }
    }

    return false;
}

bool dis(int p, int now) {
    if(abs(a[p] - b[p]) > 1  && abs(a[now] - b[now] > 1)) {
        if(a[p] > b[p]) {
            if(a[now] > b[now]) {
                swap(a[p], b[now]);
            } else {
                swap(a[p], a[now]);
            }
        } else {
            if(a[now] > b[now]) {
                swap(b[p], b[now]);
            } else {
                swap(b[p], a[now]);
            }
        }
        return true;
    } else {
        return false;

    }
}

bool fix() {
    static bool k = false;
    k =  !k;
    if(k) {
        for(int p=0,i=1; i<n; i++,p++) {
            if(dis(p,i)) {
                return true;
            }
        }
    } else {
        for(int p=n-2,i=n-1; i; i--,p--) {
            if(dis(p,i)) {
                return true;
            }
        }
    }

    return false;
}

int main(int argc, char* argv[]) {
    while(~scanf("%d",&n)) {
        for(int i=0; i<n; i++) {
            scanf("%d%d",&a[i],&b[i]);
        }
        int ans=0;
        output();
        while(check()) {
            output();
            ans++;
        }
        while(fix()) {
            output();
            //ans++;
        }
        printf("%d\n",ans);
    }

    return 0;
}

/*
5
5 5
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

*/
/*
4
aaa
aabbb
bbbb
bbbaaa

5
aaa
aabbb
bbbb
bbbbcccc
bbbbddd

aaaa
aaaa

*/



