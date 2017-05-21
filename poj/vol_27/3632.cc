#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    int a[50];
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        printf("%d\n",(*max_element(a,a+n)-*min_element(a,a+n))*2);
    }
    return 0;
}
