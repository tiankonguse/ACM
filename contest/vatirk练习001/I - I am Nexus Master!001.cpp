/*************************************************************************
    > File Name: I - I am Nexus Master!001.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/10 21:47:56
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

const double  esp = 1e-6;

struct T {
    int weeks;
    double downloaded, above , below;
    void init(int weeks, double downloaded, double above, double below) {
        this->weeks =weeks;
        this->downloaded =downloaded;
        this->above =above;
        this->below =below;
    }
} user[20];

char _map[15][30]= {
    "Peasant",
    "User",
    "Power_User",
    "Elite_User",
    "Crazy_User",
    "Insane_User",
    "Veteran_User",
    "Extreme_User",
    "Ultimate_User",
    "Nexus_Master"
};

void init() {
    user[2].init(4,50,1.05,0.95);
    user[3].init(8,120,1.55,1.45);
    user[4].init(15,300,2.05,1.95);
    user[5].init(25,500,2.55,2.45);
    user[6].init(40,750,3.05,2.95);
    user[7].init(60,1024,3.55,3.45);
    user[8].init(80,1536,4.05,3.95);
    user[9].init(100,3072,4.55,4.45);
}

int find_lev(char const* const name) {
    for(int i=0;; i++) {
        if(strcmp(name,_map[i])==0)return i;
    }
}

bool is_zero(double const& downloaded, double  const& ratio) {
    if(downloaded >= 50 && ratio < 0.4 ||
            downloaded >= 100 && ratio < 0.5 ||
            downloaded >= 200 && ratio < 0.6 ||
            downloaded >= 400 && ratio < 0.7 ||
            downloaded >= 800 && ratio < 0.8
      ) {
        return 1;
    }

    return 0;
}



int main() {
    init();
    int cas,i,now_lev,Register_time;
    char str[100];
    double downloaded, uploaded, ratio;

    scanf("%d",&cas);
    while(cas--) {
        scanf("%s%d%lf%lf",str,&Register_time,&downloaded, &uploaded);

        if(downloaded <= esp){
            printf("%s\n",_map[1]);
            continue;
        }

        ratio = uploaded/downloaded;

        bool ok = false;
        now_lev =  find_lev(str);
        for(i = 9; i>=2; i--) {
            if(Register_time >= user[i].weeks && downloaded >= user[i].downloaded) {
                if(now_lev >= i){
                    if(ratio >= user[i].below){
                        printf("%s\n",_map[i]);
                        ok = true;
                        break;
                    }
                }else{
                    if(ratio >= user[i].above){
                        printf("%s\n",_map[i]);
                        ok = true;
                        break;
                    }
                }
            }
        }
        if(ok) {
            continue;
        }

        if(is_zero(downloaded, ratio)) {
            printf("%s\n",_map[0]);
        } else {
            printf("%s\n",_map[1]);
        }

    }
    return 0;
}
