
//n = 1: 1
//n >= 2: 令i=2,把树中的1和父亲节点交换直至1成为root,
// 然后a[i]=1,a[1]=i;如此,i=2,3,4,...,(n-1),n结束.

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    if (n == 1) {
        cout<<1<<endl;
        return 0;
     }
    int i, k;
    int *a = new int[n+1];
    a[1] = 1;
    
    for (k = 2; k <= n; ++k) {
        i = k-1;
        while (i >= 2) {
            a[i] = a[i/2];
            i /= 2 ;
        }
        a[1] = k;
        a[k] = 1;
    }
    
    printf("%d",a[1]);
    for (i = 2; i <= n; ++i) {
        printf(" %d", a[i]);
    }
    puts("\n");
    delete a;
    return 0;
}

/*
360 MS
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    if (n == 1) {
        cout<<1<<endl;
        return 0;
     }
    int i, k;
    int *a = new int[n+1];
    a[1] = 1;
    
    for (k = 2; k <= n; ++k) {
        i = k-1;
        while (i >= 2) {
            a[i] = a[i/2];
            i /= 2 ;
        }
        a[1] = k;
        a[k] = 1;
    }
    
    char ch[13];
    sprintf(ch, "%d",a[1]);
    string str = ch;
    for (i = 2; i <= n; ++i) {
        sprintf(ch, " %d", a[i]);
        str += ch;
    }
    puts(str.c_str());
    delete a;
    return 0;
}
*/