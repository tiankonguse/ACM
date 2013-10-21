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

int xAxis[2400],yAxis[2400];
int xAxisNum,yAxisNum;



struct Point {
    int x,y;
    int _x,_y;
    void read() {
        scanf("%d%d",&x,&y);
        xAxis[xAxisNum++] = x;
        yAxis[yAxisNum++] = y;
    }

    void init() {
        _x = lower_bound(xAxis, xAxis+xAxisNum, x) - xAxis;
        _y = lower_bound(yAxis, yAxis+yAxisNum, y) - yAxis;
    }
};

struct Seg {
    Point begin,end;
} xSeg[610],ySeg[610], newxSeg[610],newySeg[610];

int xSegNum, ySegNum,newxSegNum, newySegNum;

int sumy[2400],oney[2400],spany[2400];

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



void init() {
    //newySeg[newySegNum++]
    for(int i=0; i<newySegNum; i++) {
        newySeg[i].begin.init();
        newySeg[i].end.init();
    }
    for(int i=0; i<xSegNum; i++) {
        xSeg[i].begin.init();
        xSeg[i].end.init();
    }
}


void addOneySeg(Seg & seg) {
    //oney
    for(int i=seg.begin._y; i<= seg.end._y; i++) {
        oney[i] = 1;
    }
}

void addxSeg(Seg & seg) {
    int _y = seg.begin._y;
    int now = spany[_y];
    if(seg.begin._x <= now) {
        spany[_y] = max(spany[_y], seg.end._x);
    }
}


int main(int argc, char* argv[]) {
    int n,i,ans;
    while(~scanf("%d",&n)) {
        xSegNum = ySegNum = ans = xAxisNum = yAxisNum = 0;
        for(i=0; i<n; i++) {
            read();
        }

        if(xSegNum < 2 || ySegNum < 2) {
            puts("0");
            continue;
        }

        sort(xAxis, xAxis+xAxisNum);
        sort(yAxis, yAxis+yAxisNum);

        xAxisNum=unique(xAxis, xAxis+xAxisNum) - xAxis;
        yAxisNum=unique(yAxis, yAxis+yAxisNum) - yAxis;

        sort(ySeg, ySeg+ySegNum, ycmp);
        sort(xSeg, xSeg+xSegNum, xcmp);

        unionySeg();

        init();

        for(i=0; i<newySegNum;) {
            //sumy[24000],oney[24000],oney[24000]
            memset(sumy, 0, sizeof(sumy));
            memset(oney, 0, sizeof(oney));

            for(int j=0; j<yAxisNum; j++) {
                spany[j] = newySeg[i].begin._x;
            }

            addOneySeg(newySeg[i]);
            i++;
            while(i< newySegNum && newySeg[i].begin.x == newySeg[i-1].begin.x) {
                addOneySeg(newySeg[i]);
                i++;
            }
            sumy[0] = oney[0];
            for(int j=1; j<yAxisNum; j++) {
                sumy[j] = sumy[j -1] + oney[j];
            }

            for(int j=0; j<xSegNum; j++) {
                addxSeg(xSeg[j]);
            }
            for(int j=0; j<yAxisNum; j++) {
                printf("%d  %d\n",sumy[j], spany[j]);
            }
            printf("i=%d  %d\n",i,newySegNum);

            for(int j=i; j<newySegNum; j++) {
                int y1 = newySeg[j].begin._y;
                int y2 = newySeg[j].end._y;
                int x = newySeg[j].begin._x;
                int num = 0,basey=-1;
                for(int k=y1; k<= y2; k++) {
                    if(oney[k] == 1) {
                        if(spany[k] >= x) {
                            if(basey == -1) {
                                basey = k;
                            } else {
                                num++;
                            }
                        }
                    } else {
                        basey=-1;
                        ans += num * (num + 1) / 1;
                        num = 0;
                    }
                }
                ans += num * (num + 1) >> 1;

            }
            printf("- %d\n",ans);

        }
        printf("%d\n",ans);

    }

    return 0;
}







