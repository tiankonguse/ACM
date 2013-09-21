/*************************************************************************
    > File Name: I - I am Nexus Master!.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/10 20:45:56
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;

struct T{
    int weeks;
    double downloaded, above , below;
    void init(int weeks, double downloaded, double above, double below){
        this->weeks =weeks;
        this->downloaded =downloaded;
        this->above =above;
        this->below =below;
    }
}user[20];

char map[15][30]={"Power_User","Elite_User","Crazy_User","Insane_User","Veteran_User","Extreme_User","Ultimate_User","Nexus_Master"};
char _map[15][30]={"Peasant","User","Power_User","Elite_User","Crazy_User","Insane_User","Veteran_User","Extreme_User","Ultimate_User","Nexus_Master"};
char out[2][30]={"Peasant","User"};

void init(){
    user[2].init(4,50,1.05,0.95);
    user[3].init(8,120,1.55,1.45);
    user[4].init(15,300,2.05,1.95);
    user[5].init(25,500,2.55,2.45);
    user[6].init(40,750,3.05,2.95);
    user[7].init(60,1024,3.55,3.45);
    user[8].init(80,1536,4.05,3.95);
    user[9].init(100,3072,4.55,4.45);
}

int find_pos(char* name){
    for(int i=0;;i++){
        if(strcmp(name,map[i])==0)return i;
    }
}

char* get(double downloaded, double ratio){
    if(downloaded >= 50 && ratio < 0.4){
        return out[0];
    }
    if(downloaded >= 100 && ratio < 0.5){
        return out[0];
    }
    if(downloaded >= 200 && ratio < 0.6){
        return out[0];
    }
    if(downloaded >= 400 && ratio < 0.7){
        return out[0];
    }
    if(downloaded >= 800 && ratio < 0.8){
        return out[0];
    }

    return out[1];
}

bool is_zero(double downloaded, double ratio){
    if(downloaded >= 50 && ratio < 0.4){
        return 1;
    }
    if(downloaded >= 100 && ratio < 0.5){
        return 1;
    }
    if(downloaded >= 200 && ratio < 0.6){
        return 1;
    }
    if(downloaded >= 400 && ratio < 0.7){
        return 1;
    }
    if(downloaded >= 800 && ratio < 0.8){
        return 1;
    }

    return 0;
}

int up(int now_lev,int Register_time,double downloaded,double ratio){
    if(lev == 0){

    }
}

int main() {
    init();
    int cas,i;
    char str[100];
    int Register_time, pos;
    double downloaded, uploaded, ratio;


    //Crazy_User 15 800.00 639.99 uploaded/downloaded
    scanf("%d",&cas);
    int up_lev, now_lev;
    while(cas--){
        scanf("%s%d%lf%lf",str,&Register_time,&downloaded, &uploaded);
        ratio = uploaded/downloaded;



//        printf("%lf ",ratio);

        if(strcmp(str,"Peasant")==0){
            up_lev = up(0,Register_time,downloaded,ratio);
            printf("%s\n",_map[up_lev]);
            continue;
        }

        if(strcmp(str,"User")==0){
            up_lev = up(1,Register_time,downloaded,ratio);
            if(up_lev != 1){
                printf("%s\n",_map[up_lev]);
            }else{
                printf("%s\n",get(downloaded,ratio));
            }
            continue;
        }

        pos =  find_pos(str);

//        printf("pos = %d %lf ",pos, user[pos].below);

        now_lev = pos + 2;

        up_lev = up(now_lev,Register_time,downloaded,ratio);

        if(up_lev > now_lev){
            printf("%s\n",_map[up_lev]);
            continue;
        }

        if(ratio >= user[pos].below){
            printf("%s\n",str);
            continue;
        }

//        printf("---");

        bool ok = false;
        for(i = pos-1;i>=0;i--){

            if(ratio >= user[i].above){
                printf("%s\n",map[i]);
                ok = true;
                break;
            }
        }
        if(ok){
            continue;
        }

        printf("%s\n",get(downloaded,ratio));

    }
    return 0;
}
