#include <iostream>
#include <vector>
#include <string>
using namespace std;

//用素数表判定素数,先调用initprime
int plist[1500],pcount=0;

int prime(int n){
    int i;
    if ((n!=2&&!(n%2))||(n!=3&&!(n%3))||(n!=5&&!(n%5))||(n!=7&&!(n%7)))
        return 0;
    for (i=0;plist[i]*plist[i]<=n;i++)
        if (!(n%plist[i]))
            return 0;
    return n>1;
}

void initprime(){
    int i;
    for (plist[pcount++]=2,i=3;i<=10000;i++)
        if (prime(i))
            plist[pcount++]=i;
//    cout<<pcount<<endl;
}

int main()
{
    long n, i, j, sum, cnt;
    initprime();
    while (scanf("%d", &n) == 1 && n) {
        cnt = 0;
        for (i = 0 ; i < 1230 ; ++i) {
            if (plist[i] > n) {
                break;
            }
            sum = 0;            
            j = i;
            while (sum < n) {
                sum += plist[j];
                ++j;
            }
            if (sum == n) {
                ++cnt;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
