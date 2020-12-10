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
#include<stdarg.h>
#include <assert.h>
using namespace std;
#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif
#include <time.h>
int n,a[12345];
int b[12345];
int c[12345];
int d[12345]= {0,2,3,1};



void quicksort(int l, int r) {
    int i, j;
    if(l >= r)return ;
    i = l, j = r;
    int  key;

    key = a[i];
    while(i < j) {
        // a[i] = key
        while(a[j] >= key && i < j) {
            j--;
        }

        //  i - j a[j] < key a[i] = key
        if(i < j) {
            swap(a[i], a[j]);
            i++;
        }
        // a[j] = key
        while(a[i] <= key && i < j) {
            i++;
        }

        //  i - j  a[i] > key a[j] = key
        if(i < j) {
            swap(a[i], a[j]);
            j--;
        }
    }
    quicksort(l, i-1);
    quicksort(i+1, r);
}
void quicksort1(int l, int r) {
    int i, j;
    if(l >= r)return ;
    i = l, j = r;
    int  key;

    key = a[i];
    while(i < j) {
        // a[i] = key
        while(a[j] >= key && i < j) {
            j--;
        }

        //  i - j a[j] < key a[i] = key
        if(i < j) {
            a[i] = a[j];
            i++;
        }
        // a[j] = key
        while(a[i] <= key && i < j) {
            i++;
        }

        //  i - j  a[i] > key a[j] = key
        if(i < j) {
            a[j] = a[i];
            j--;
        }
    }
    assert(i ==j);
    a[i] = key;
    quicksort1(l, i-1);
    quicksort1(i+1, r);
}
int main() {
    int i,count=0,sum=0;

    n  =1000;
    srand (time(NULL));
    bool ok = true;
    int num = 0;
    int base = 10000;
    while(1) {
            num++;
        for(i=1; i<=n; i++) {
            c[i] = a[i] = b[i] = rand()%1000;
        }

        quicksort1(1,n);
        sort(b+1, b+n+1);
        ok = true;
        for(i=1; i<=n; i++) {
            if(a[i] != b[i]) {
                ok = false;
                break;
            }
        }
        if(ok == false) {
            for(i=1; i<=n; i++) {
                a[i] = c[i];
            }
            quicksort(1,n);

            printf("quickSort error\n");
            printf("c : ");
            for(i=1; i<=n; i++) {
                printf("%2d ",c[i]);

            }
            printf("\n");
            printf("a : ");
            for(i=1; i<=n; i++) {
                printf("%2d ",a[i]);

            }
            printf("\n");
            printf("b : ");
            for(i=1; i<=n; i++) {
                printf("%2d ",b[i]);
            }
            printf("\n");
            break;
        }
        if(num%base == 0){

            printf("next %d\n",num/base);
        }



    }
    return 0;
}
