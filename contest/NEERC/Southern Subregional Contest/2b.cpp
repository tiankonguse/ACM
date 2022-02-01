/*************************************************************************
    > File Name: b.cpp
    > Author: tiankonguse
    > Mail: i@tiankonguse.com
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<string>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;
const int N = 300010;
int m,n;
double r;
double x[N];
double c[N];

int main() {
    int pos;
    double tmp;
    int leftLable,rightLable;
    double leftReal,rightReal;
    double ans = 0;
    while(~scanf("%d%d%lf",&m,&n,&r)) {
        r = r*r;
        for(int i=0; i<m; i++) {
            scanf("%lf",&c[i]);
        }
        for(int i=0; i<n; i++) {
            scanf("%lf",&x[i]);
        }

        for(int i=0; i<m; i++) {
            tmp = x[0] - c[i];
            if(tmp * tmp + 1 <= r) {
                pos = i;
                break;
            }
        }
        leftLable = rightLable = 0;
        leftReal= rightReal = x[0];
        bool ok = true;
        ans = 0;

//        for(int i=1; i<n; i++) {
//            tmp = x[i] - c[pos];
//            if(tmp * tmp + 1 <= r) {
//                //所有人一直可以照射到
//                if(x[i]  < leftReal) {
//                    leftReal = x[i];
//                    leftLable = i;
//                }
//                if(x[i] > rightReal) {
//                    rightReal = x[i];
//                    rightLable = i;
//                }
//            } else {
//                if(x[i] < c[pos]) {
//                    //人在左边
//                    bool ok = true;
//                    bool okok = false;
//                    while(ok) {
//                        pos--;
//                        tmp = c[pos] - x[rightLable];
//                        if(tmp * tmp + 1 <= r) {
//                            //这个说明移动到下一个可以照到之前的所有人
//                            tmp = c[pos] - x[i];
//                            if(tmp * tmp +1 <= r) {
//                                //移动到下个位置可以照到之前的所有人和当前人
//                                leftReal = x[i];
//                                leftLable = i;
//                                ok = false;
//                                continue;
//                            } else {
//                                //移动到下个位置，看pos是否能够到达i
//                                continue;
//                            }
//                        } else {
//                            pos++;
//                            okok = true;
//                            break;
//
//                        }
//                    }
//                    if(okok) {
//                        break;
//                    }
//                } else {
//                    //人在右边
//                    bool ok = true;
//                    bool okok = false;
//                    while(ok) {
//                        pos++;
//                        tmp = c[pos] - x[leftLable];
//                        if(tmp * tmp + 1 <= r) {
//                            //这个说明移动到下一个可以照到之前的所有人
//                            tmp = c[pos] - x[i];
//                            if(tmp * tmp +1 <= r) {
//                                //移动到下个位置可以照到之前的所有人和当前人
//                                rightReal = x[i];
//                                rightLable = i;
//                                ok = false;
//                                continue;
//                            } else {
//                                //移动到下个位置，看pos是否能够到达i
//                                continue;
//                            }
//                        } else {
//                            pos--;
//                            okok = true;
//                            break;
//
//                        }
//                    }
//                    if(okok) {
//                        break;
//                    }
//                }
//            }
//        }




    }
    return 0;
}
