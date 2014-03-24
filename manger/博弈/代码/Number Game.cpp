/*************************************************************************
    > File Name: Number Game.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/27 19:39:23
 ************************************************************************/

#include<stdio.h>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<map>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

int str[22];
bool have[22];
vector<int>ans;
int n;

map<string,int>Map;
map<string,int>::iterator it;

void init() {
    memset(have,true,sizeof(have));
    for(int i=0; i<n; i++) {
        have[str[i]] = false;
    }
}

void push(int val,int* array,int& size) {

    size = 0;
    array[size++] = val;
    have[val] = true;

    for(int i=2,v; i<=20; i++) {
        v = i+val;
        if(have[i] && v <= 20 && !have[v]) {
            array[size++] = v;
            have[v] = true;
        }
    }
}

void pop(int* array,int size) {
    for(int i=0; i<size; i++) {
        have[array[i]] = false;
    }
}

bool dfs(int val) {

    char s[22];
    int array[22],size;
    push(val,array,size);

    s[n] = '\0';
    for(int i=0;i<n;i++){
        if(have[str[i]]){
            s[i] = '0';
        }else{
            s[i] ='1';
        }
    }
    it = Map.find(s);
    if(it != Map.end()){
        pop(array,size);
//        printf("--val=%d  %d  %s\n",val,Map[s],s);
        return Map[s];
    }


    for(int i=0; i<n; i++) {
        if(!have[str[i]] && dfs(str[i])) {
             pop(array,size);
             Map[s] = 0;
            return false;
        }
    }
    pop(array,size);
    Map[s] = 1;
    return true;
}

int main() {
    int i,j,size,cas=1;
    while(scanf("%d",&n),n) {
        for(i=0; i<n; i++) {
            scanf("%d",&str[i]);
        }
        ans.clear();
        Map.clear();

        init();
        for(i=0; i<n; i++) {
            if(dfs(str[i])) {
                ans.push_back(str[i]);
            }
        }
        size = ans.size();
        if(size == 0) {
            printf("Test Case #%d\nThere's no winning move.\n\n",cas++);
        } else {
            printf("Test Case #%d\nThe winning moves are:",cas++);
            sort(ans.begin(),ans.end());
            for(i=0; i<size; i++) {
                printf(" %d",ans[i]);
            }
            printf("\n\n");
        }
    }

    return 0;
}
