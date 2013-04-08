#include<iostream>
#include<cstdio>
#include<set>
#include<cstring>
#include<cstdlib>
#include<functional>
#include<functional>
#include<algorithm>
using namespace std;

const int N = 100003<<1;
int str[N];
int p[N];

int Manacher(int n){

    int mx = 0, id = 0, ans = 1, left, right;

    p[0]=0;

    for(int i = 1; i < n; i++){
        p[i] = 1;

        if(mx > i){
            p[i] = p[2 * id - i];
            if(mx - i < p[i])p[i] = mx-i;
        }

        //向两端配匹
        while(str[i - p[i]] == str[i + p[i]]){
            if(str[i - p[i]] == 1){
                p[i]++;
            }else{
                left = i - p[i];
                right = i + p[i];

                if(left + 2 > right - 2
                   || (left + 2 <= right - 2 && str[left] <= str[left+2])){
                    p[i]++;
                }else{
                    break;
                }
            }
        }

        if(p[i] > ans)ans = p[i];

        if(i + p[i]>mx){
            mx = i + p[i];
            id = i;
        }

    }

    return ans;
}

int main(){

    int cas,m,j,i;

    scanf("%d",&cas);

    while(cas--){
        scanf("%d",&m);
        j = 0;
        str[j++] = 0;
        str[j++] = 1;
        for(i = 0; i < m; i++){
            scanf("%d", &str[j++]);
            str[j++] = 1;
        }
        str[j] = 2;

        printf("%d\n", Manacher(j) -1);

    }


    return 0;
}
