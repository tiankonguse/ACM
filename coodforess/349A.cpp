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

int main() {

    int have_25,have_50;
    int n,tmp;
    bool ok;
    while(~scanf("%d",&n)){
        have_25 = 0;
        have_50 = 0;
        ok = true;

        while(n--){
            scanf("%d",&tmp);
            if(ok){
                if(tmp == 100){
                    if(have_50 >= 1 && have_25 >= 1){
                        have_50--,have_25--;
                    }else if(have_25 >= 3){
                        have_25 -= 3;
                    }else{
                        ok = false;
                    }
                }else if(tmp == 50){
                    if(have_25 >= 1){
                        have_25--;
                        have_50++;
                    }else{
                        ok = false;
                    }

                }else{
                    have_25++;
                }
            }
        }
        printf("%s\n",ok?"YES":"NO");
    }

    return 0;
}

