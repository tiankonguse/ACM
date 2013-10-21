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

struct Point {
    int x,y;
    void read() {
        scanf("%d%d",&x,&y);
    }
};

struct Seg {
    Point begin,end;
} xSeg[610],ySeg[610], newxSeg[610],newySeg[610];

int xSegNum, ySegNum,newxSegNum, newySegNum;


bool ycmp(Seg a, Seg b) {
    if(a.begin.x != b.begin.x) {
        return a.begin.x < b.begin.x;
    } else {
        return a.begin.y < b.begin.y;
    }
}
bool xcmp(Seg a, Seg b) {
    if(a.begin.y != b.begin.y) {
        return a.begin.y < b.begin.y;
    } else {
        return a.begin.x < b.begin.x;
    }
}

void  unionySeg() {
    newySegNum = 0;
    newySeg[newySegNum++] = ySeg[0];
    for(int i=1; i<ySegNum; i++) {
        if(ySeg[i].begin.x == newySeg[newySegNum-1].end.x) {
            if(ySeg[i].begin.y <= newySeg[newySegNum-1].end.y) {
                newySeg[newySegNum-1].end.y = max(newySeg[newySegNum-1].end.y, ySeg[i].begin.y);
            } else {
                newySeg[newySegNum++] = ySeg[i];
            }
        } else {
            newySeg[newySegNum++] = ySeg[i];
        }

    }
}


void unionxSeg() {
    newxSegNum = 0;
    newxSeg[newxSegNum++] = xSeg[0];
    for(int i=1; i<xSegNum; i++) {
        if(xSeg[i].begin.y == newxSeg[newxSegNum-1].end.y) {
            if(xSeg[i].begin.x <= newxSeg[newxSegNum-1].end.x) {
                newxSeg[newxSegNum-1].end.x = max(newxSeg[newxSegNum-1].end.x, xSeg[i].begin.x);
            } else {
                newxSeg[newxSegNum++] = xSeg[i];
            }
        } else {
            newxSeg[newxSegNum++] = xSeg[i];
        }

    }
}

void read() {
    Point begin,end;
    begin.read();
    end.read();
    if(begin.x == end.x) {
        if(begin.y > end.y) {
            swap(begin.y, end.y);
        }
        ySeg[ySegNum].begin = begin;
        ySeg[ySegNum].end = end;
        ySegNum++;
    } else {
        if(begin.x > end.x) {
            swap(begin.x, end.x);
        }
        xSeg[xSegNum].begin = begin;
        xSeg[xSegNum].end = end;
        xSegNum++;
    }
}


int main(int argc, char* argv[]) {
    int n,ans;
    while(~scanf("%d",&n)) {
        xSegNum = ySegNum = ans = 0;
        for(int i=0; i<n; i++) {
            read();
        }

        if(xSegNum < 2 || ySegNum < 2) {
            puts("0");
            continue;
        }

        sort(ySeg, ySeg+ySegNum, ycmp);
        sort(xSeg, xSeg+xSegNum, xcmp);

        unionySeg();
        unionxSeg();

//        for(int i=0; i<newxSegNum; i++) {
//            printf("x:%d %d y:%d\n",newxSeg[i].begin.x, newxSeg[i].end.x, newxSeg[i].end.y);
//        }
//
//        for(int i=0; i<newySegNum; i++) {
//            printf("x:%d y:%d %d\n",newySeg[i].begin.x,newySeg[i].begin.y, newySeg[i].end.y);
//        }


        for(int i=0; i<newxSegNum; i++) {
            for(int j=i+1; j<newxSegNum; j++) {
                if(newxSeg[i].begin.y == newxSeg[j].begin.y) {
                    continue;
                }

                for(int k=0; k<newySegNum; k++) {
                    if(newySeg[k].begin.x < newxSeg[i].begin.x || newySeg[k].begin.x > newxSeg[i].end.x ) {
                        continue;
                    }

                    if(newxSeg[i].begin.y < newySeg[k].begin.y || newxSeg[i].begin.y > newySeg[k].end.y) {
                        continue;
                    }

                    if(newySeg[k].begin.x < newxSeg[j].begin.x || newySeg[k].begin.x > newxSeg[j].end.x ) {
                        continue;
                    }

                    if(newxSeg[j].begin.y < newySeg[k].begin.y || newxSeg[j].begin.y > newySeg[k].end.y) {
                        continue;
                    }

                    for(int l=k+1; l<newySegNum; l++) {

                        if(newySeg[k].begin.x == newySeg[l].begin.x) {
                            continue;
                        }
//                        puts("here");
                        if(newySeg[l].begin.x < newxSeg[i].begin.x || newySeg[l].begin.x > newxSeg[i].end.x ) {
                            continue;
                        }


                        if(newxSeg[i].begin.y < newySeg[l].begin.y || newxSeg[i].begin.y > newySeg[l].end.y) {
                            continue;
                        }

                        if(newySeg[l].begin.x < newxSeg[j].begin.x || newySeg[l].begin.x > newxSeg[j].end.x ) {
                            continue;
                        }


                        if(newxSeg[j].begin.y < newySeg[l].begin.y || newxSeg[j].begin.y > newySeg[l].end.y) {
                            continue;
                        }

                        ans++;
                    }
                }
            }
        }

        printf("%d\n",ans);

    }

    return 0;
}
/*

8
1 0 4 0
2 1 2 0
0 0 0 3
2 2 2 3
3 3 3 -1
0 3 4 3
4 1 -1 1
3 2 -1 2
*/






