/*************************************************************************
    > File Name: Image Is Everything.cpp
    > Author: tiankonguse
    > Mail: i@tiankonguse.com
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

const int maxn = 11;
char cub[maxn][maxn][maxn];
int n;
char view[6][maxn][maxn];

void get(int k,int i,int j,int p,int &x, int &y,int &z) {
    if(k==0) {
        x = p;
        y=j;
        z = i;
    } else if(k==1) {
        x = n-1-j;
        y=p;
        z=i;
    } else if(k==2) {
        x=n-1-p;
        y=n-1-j;
        z=i;
    } else if(k==3) {
        x = j;
        y= n-1-p;
        z=i;
    } else if(k==4) {
        x=n-1-i;
        y=j;
        z=p;
    } else {
        x=i;
        y=j;
        z=n-1-p;
    }
}

//ront, left, back, right, top, bottom
int main() {
    int i,j,k,x,y,z,m,ans;
    while(~scanf("%d",&n),n) {
        memset(cub, '#',sizeof(cub));
        for(i=0; i<n; i++) {
            for(k=0; k<6; k++) {
                scanf("%s",view[k][i]);
            }
        }

        for(k=0; k<6; k++) {
            for(i=0; i<n; i++) {
                for(j=0; j<n; j++) {
                    if(view[k][i][j] == '.') {
                        for(m=0; m<n; m++) {
                            get(k,i,j,m,x,y,z);
                            cub[x][y][z] = '.';
                        }
                    }
                }
            }
        }

        while(1) {
            bool done = true;
            for(k=0; k<6; k++) {
                for(i=0; i<n; i++) {
                    for(j=0; j<n; j++) {
                        if(view[k][i][j] != '.') {
                            for(m=0; m<n; m++) {
                                get(k,i,j,m,x,y,z);
                                if(cub[x][y][z] == '.') {
                                    continue;
                                }
                                if(cub[x][y][z] == '#') {
                                    cub[x][y][z] = view[k][i][j];
//                                    printf("x=%d  y=%d  z=%d  k=%d  i=%d  j=%d\n",x,y,z,k,i,j);
                                    break;
                                }
//                                printf("%c  %c  %d  %d  %d\n",cub[x][y][z],view[k][i][j],k,i,j);
                                if(cub[x][y][z] == view[k][i][j]) {
                                    break;
                                }
                                cub[x][y][z] = '.';
                                done = false;
//                                printf("%c %d %d %d \n",cub[x][y][z],x,y,z);
                            }
                        }
                    }
                }
            }
            if(done) {
                break;
            }
        }
        ans = 0;
        for(i=0; i<n; i++) {
            for(j=0; j<n; j++) {
                for(k=0; k<n; k++) {
                    if(cub[i][j][k] != '.') {
                        ans++;
                    }
                }
            }
        }
        printf("Maximum weight: %d gram(s)\n",ans);

    }

    return 0;
}
