#include<bits/stdc++.h>
#include <stdio.h>

using namespace std;

void split(char* p, vector<string>& vec){
    vec.clear();
    string tmp;

    while(*p != '\0'){
        if(*p == ':'){
            if(!tmp.empty()){
                vec.push_back(tmp);
                tmp.clear();
            }
            vec.push_back(":");
        }else{
            tmp.push_back(*p);
        }
        p++;
    }
    if(!tmp.empty()){
        vec.push_back(tmp);
        tmp.clear();
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--){

    }

    return 0;
}


