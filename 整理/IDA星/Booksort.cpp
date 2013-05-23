/*************************************************************************
    > File Name: Booksort.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/23 12:59:33
 ************************************************************************/

#include<cstdio>
#include<cstring>
using namespace std;

int n,str[20], _maxDepth;


int hfunc() {
    int depth = 0;
    for(int i=1; i<n; i++) {
        if(str[i] != str[i-1]+1) {
            depth++;
        }
    }
    return depth;
}

void move(int left, int mid, int right) {
    int i, j, tmp[20];;
    for(i=mid+1,j=0; i<=right; i++,j++) {
        tmp[j] = str[i];
    }
    for(i=left; i<=mid; i++,j++) {
        tmp[j] = str[i];
    }
    for(i=left,j=0; i<=right; i++,j++) {
        str[i] = tmp[j];
    }
}

int dfs(int depth) {
    int left,mid,right,h;
    for(left=0; left<n-1; left++) {
        while(left && str[left] == str[left-1]+1)left++;
        for(mid = left; mid<n-1; mid++) {
            while(mid<n-1 && (str[mid]+1 == str[mid+1]))mid++;
            for(right = mid+1; right < n; right++) {
                while(right<n-1 && (str[right]+1 == str[right+1]))right++;
                move(left, mid,right);
                if((h = hfunc()) == 0)return 1;
                if(depth*3 + h <= _maxDepth*3) {
                    if(dfs(depth+1)) {
                        return 1;
                    }
                }
                move(left,left + (right-mid-1),right);
            }

        }

    }
    return 0;
}

int main() {
    int cas,i;
    scanf("%d",&n);
    for(i=0; i<n; i++) {
        scanf("%d",&str[i]);
    }
    _maxDepth = (hfunc()+2)/3;
    if(_maxDepth) {
        while(dfs(1) == 0) {
            _maxDepth++;
        }
    }
    printf("%d\n",_maxDepth);
return 0;
}
/*
6
1 3 4 6 2 5
5
5 4 3 2 1
10
6 8 5 3 4 7 2 9 1 10
*/
