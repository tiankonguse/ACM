/*************************************************************************
    > File Name: D.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/4/29 11:01:00
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

struct T{
    int left,right;
    T* next;
}str[222],*head, *that;

int top;


void insert(int l,int r){
    that = &str[top++];
    that->left = l;
    that->right = r;

    head = &str[0];

    while(head->next != NULL && head->next->left <= that->left){
        head = head->next;
    }

    that->next = head->next;
    head->next = that;
}

void find(){
    int r = 0;
    head = &str[0];

    while(head->next != NULL){
        if(head->next->left <= r){
             head = head->next;
        }else{
            r = head->next->right;
            head->next = head->next->next;
        }
    }
}

int main() {

    int t, n, l, r, ans, i;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        str[0].next = NULL;
        top = 1;

        for(i=0;i<n;i++){
            scanf("%d%d",&l,&r);
            l = (l+1)>>1;
            r = (r+1)>>1;
            if(l>r){
                l ^= r, r ^= l, l ^= r;
            }
            insert(l,r);
        }

        ans = 0;
        while(str[0].next != NULL){
            ans += 10;
            find();
        }
        printf("%d\n",ans);

    }


    return 0;
}


