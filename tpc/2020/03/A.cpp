#include<bits/stdc++.h>
#include <stdio.h>

using namespace std;


int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        char str[30];
        scanf("%d %s", &n, str);
        string s = str;
        if(s == "divide_by_three"){
            printf("%d\n", (3 - (n%3)) % 3);
        }else if(s == "divide_by_four"){
            printf("%d\n", (4 - (n%4)) % 4);
        }else if(s == "divide_by_five"){
            printf("%d\n", (5 - (n%5)) % 5);
        }else{
            if(n == 1 || n == 4 || n == 6){
                printf("%d\n", 1);
            }else if(n == 8){
                printf("%d\n", 3);
            }else if(n == 9){
                printf("%d\n", 2);
            }else{
                printf("%d\n", 0);
            }
        }
    }


    return 0;
}
