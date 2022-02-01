#include<cstdio>
#include<cstdlib>
#include<cstring>
#include <iostream>     // std::istream, std::cout
#include <string>       // std::string
#include <sstream>      // std::stringstream
#include <locale>       // std::isspace, std::isdigit
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
#include<stdarg.h>
using namespace std;
#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif

typedef class Lottery {
    static const int N = 101;
    static const int M = 9;
    LL ans00[N][M];
    LL ans01[N][M];
    LL ans10[N][M];
    LL ans11[N][M];

    void getAns00() {
        for(int i=1; i<N; i++) {
            ans00[i][0] = 1;
            for(int j=1; j<M; j++) {
                ans00[i][j] = ans00[i][j-1] * i;
            }
        }
    }


    void getAns01() {
        for(int i=1; i<N; i++) {
            ans01[i][0] = 1;
            for(int j=1; j<=min(i,M-1); j++) {
                ans01[i][j] = ans01[i-1][j-1] * i;
            }
        }
    }

    void getAns10() {
        for(int i=1; i<N; i++) {
            ans10[i][0] = 1;
            for(int j=1; j<M; j++) {
                ans10[i][j] = ans10[i-1][j] + ans10[i][j-1];
            }
        }
    }

    void getAns11() {
        for(int i=1; i<N; i++) {
            ans11[i][0] = 1;
            for(int j=1; j<=min(i,M-1); j++) {
                ans11[i][j] = ans11[i-1][j] + ans11[i-1][j-1];
            }
        }
    }


    struct T {
        string name;
        LL score;
        bool operator<(T o)const {
            return this->score == o.score ? this->name < o.name :this->score < o.score;
        }
    };

    T const  getT(string rule) {
        T tmp;

        int position = rule.find(":");

        tmp.name = rule.substr(0, position);

        rule = rule.substr(position+1);

        std::stringstream in(rule.c_str());

        int n,m;
        string s,u;
        in>>n>>m>>s>>u;

        if(s == "F" && u == "F") {
            tmp.score = ans00[n][m];
        } else if(s == "F" && u == "T") {
            tmp.score = ans01[n][m];
        } else if(s == "T" && u == "F") {
            tmp.score = ans10[n][m];
        } else {
            tmp.score = ans11[n][m];
        }

        return tmp;
    }

public:
    Lottery() {
        memset(ans00,0,sizeof(ans00));
        memset(ans01,0,sizeof(ans01));
        memset(ans10,0,sizeof(ans10));
        memset(ans11,0,sizeof(ans11));
        ans00[0][0] = 1;
        ans01[0][0] = 1;
        ans10[0][0] = 1;
        ans11[0][0] = 1;

        getAns00();
        getAns01();
        getAns10();
        getAns11();

    }



    vector <string> sortByOdds(vector <string>& rules) {
        vector <T> ans;
        for(int i=0; i<rules.size(); i++) {
            ans.push_back(getT(rules[i]));
        }

        sort(ans.begin(),ans.end());

        rules.clear();
        for(int i=0; i<ans.size(); i++) {
            rules.push_back(ans[i].name);
            cout<<ans[i].name<<endl;
        }

        return rules;
    }
} Two;


int main() {

    Two two;
    vector <string> rules;
    char in[3000];
    while(gets(in)) {
        rules.push_back(in);
    }
    two.sortByOdds(rules);
    return 0;
}

/*
PICK ANY TWO: 10 2 F F
PICK TWO IN ORDER: 10 2 T F
PICK TWO DIFFERENT: 10 2 F T
PICK TWO LIMITED: 10 2 T T


INDIGO: 93 8 T F
ORANGE: 29 8 F T
VIOLET: 76 6 F F
BLUE: 100 8 T T
RED: 99 8 T T
GREEN: 78 6 F T
YELLOW: 75 6 F F




*/
