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

const int width = 2;
const int N = 10;
map<string,int>mHeadTail[width];
map<string,string>preHeadTail[width];
queue<string>qHeadTail[width];

int str[width][N];
int n;
int ans;
bool ansFind;



void init() {
    int i,j;
    string sHead = "", sTail = "";

    for(i=0; i<width; i++) {
        mHeadTail[i].clear();
        preHeadTail[i].clear();
        while(!qHeadTail[i].empty())qHeadTail[i].pop();
    }


    for(i=1; i<=n; i++) {
        for(j=0; j<width; j++) {
            sHead += (str[j][i] + '0');
        }
    }
    mHeadTail[0][sHead] = 0;
    qHeadTail[0].push(sHead);
    preHeadTail[0][sHead] = "begin";


    for(i=1; i<=n; i++) {
        for(j=0; j<width; j++) {
            sTail += (i + '0');
        }
    }
    mHeadTail[1][sTail] = 0;
    qHeadTail[1].push(sTail);
    preHeadTail[1][sTail] = "end";

    ans  = 0;
    if(sTail == sHead) {
        ansFind = true;
    } else {
        ansFind = false;
    }
}

void toArray(string& s) {
    int i,k=0;
    for(i=1; i<=n; i++) {
        str[0][i] = s[k++];
        str[1][i] = s[k++];
    }
}

void toString(string& s) {
    s = "";
    int i;

    for(i=1; i<=n; i++) {
        if(str[0][i] > str[1][i]) {
            s += str[1][i];
            s += str[0][i];
        } else {
            s += str[0][i];
            s += str[1][i];
        }
    }

}

void outputhead(int step, string&s, int i = 0) {
    map<string, string>::iterator  it = preHeadTail[i].find(s);
    if(it != preHeadTail[i].end()) {
        outputhead(step-1, it->second);
    }
    printf("%d:%s\n",step, s.c_str());
}

void outputtail(int step, string&s, int i = 1) {
    printf("%d:%s\n",step, s.c_str());
    map<string, string>::iterator  it = preHeadTail[i].find(s);
    if(it != preHeadTail[i].end()) {
        outputtail(step+1, it->second);
    }
}

void bfsHeadTail(int v) {
    string s = qHeadTail[v].front();
    qHeadTail[v].pop();
    string sHeadTail = s;
    int step = mHeadTail[v][s];
    int i,j,k;
    map<string, int>::iterator itHeadTail;

    toArray(s);

    for(i=1; i<=n; i++) {
        for(j=0; j<width; j++) {
            for(k=0; k<width; k++) {
                if(str[j][i] == str[k][i+1])continue;
                if(j == 1 && str[1][i] == str[0][i])continue;
                if(k == 1 && str[1][i+1] == str[0][i+1])continue;
                swap(str[j][i],str[k][i+1]);
                toString(s);
                itHeadTail = mHeadTail[v].find(s);
                if(itHeadTail == mHeadTail[v].end()) {
                    itHeadTail = mHeadTail[!v].find(s);
                    if(itHeadTail == mHeadTail[!v].end()) {
                        //head,tail all not find
                        mHeadTail[v][s] = step + 1;
                        qHeadTail[v].push(s);
                        preHeadTail[v][s] = sHeadTail;
                    } else {
                        ansFind = true;
                        ans = step + itHeadTail->second + 1;
                        if(!v) {
                            outputhead(step, sHeadTail);
                            outputtail(step+1, s);
                        } else {
                            outputhead(itHeadTail->second, s);
                            outputtail(itHeadTail->second+1, sHeadTail);
                        }

                    }
                }

                if(ansFind) {
                    return ;
                }
                swap(str[j][i],str[k][i+1]);
            }
        }
    }

}


void bfs() {
    while(!ansFind) {
        if(!ansFind) {
            bfsHeadTail(0);
        }
        if(!ansFind) {
            bfsHeadTail(1);
        }
    }
}

int main(int argc, char* argv[]) {
    while(~scanf("%d",&n)) {
        for(int i=1; i<=n; i++) {
            scanf("%d%d",&str[0][i],&str[1][i]);
            if(str[0][i]>str[1][i])swap(str[0][i],str[1][i]);
        }
        init();
        if(!ansFind) {
            bfs();
        }
        printf("%d\n",ans);
        break;
    }

    return 0;
}

/*
8
8 8
7 7
6 6
5 5
4 4
3 3
2 2
1 1

7
7 7
6 6
5 5
4 4
3 3
2 2
1 1

6
6 6
5 5
4 4
3 3
2 2
1 1

5
5 5
4 4
3 3
2 2
1 1



4
4 4
3 3
2 2
1 1

5
1 5
3 4
2 5
2 3
1 4

8
8 3
4 2
6 4
3 5
5 8
7 1
2 6
1 7

*/
