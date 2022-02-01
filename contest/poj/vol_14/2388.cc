#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
   // freopen("in.txt","r",stdin);
    int N;
    int a[10001];
    scanf("%d",&N);
    for(int i=0;i<N;i++){
       scanf("%d",&a[i]);
    }
    std::sort(a,a+N);
    printf("%d\n",a[(N-1)/2]);
    return 0;
}
