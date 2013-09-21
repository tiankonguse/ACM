/*************************************************************************
    > File Name: C Party.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/12 19:10:02
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
const int N = 10010;
const int D = 25;
double str[D][N];

double get(double pos, double *array,int n){
    int i;
    double sum = 0;
    for(i=0;i<n;i++){
        sum += (pos - array[i])*(pos - array[i]);
    }
    return sum;
}

double three(double* array, int n){
    double sum;
    double left = array[0];
    double right = array[n-1];

    double left_val = get(left,array,n);
    double right_val = get(right,array,n);

    while(left + 1e-5 <= right){
        if(left_val > right_val){
            left = (right - left)/3 + left;
            left_val = get(left,array,n);
        }else{
            right = (right - left)*2/3 + left;
            right_val = get(right,array,n);
        }
    }
    return left_val;
}

int main() {

    int cas,n,d,i,j;
    double ans;
    scanf("%d",&cas);
    while(cas--){
        scanf("%d%d",&n,&d);
        for(i=0;i<n;i++){
            for(j=0;j<d;j++){
                scanf("%lf",&str[j][i]);
            }
        }
        ans = 0;

        for(i=0;i<d;i++){
            sort(str[i],str[i]+n);
            ans += three(str[i],n);
        }
        printf("%.3f\n",ans);
    }


    return 0;
}
