#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<cstdlib>
#include<cassert>
#include<vector>
#include<set>
using namespace std;
#define N 55
int n , m;
char s[N][N];
bool f[N][N];
char str[100004];
int l , L[26];
char fun[26][10005];
char var[26][3];
int num[26];

int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};
int X , Y , D;
vector< pair<int , int> > res;

void work(char T) {
    if (T == 'L')
        D = (D + 3) & 3;
    else if (T == 'R')
        D = (D + 1) & 3;
    else if (T == 'C') {
        int x = X + dx[D] , y = Y + dy[D];
        if (x > 0 && x <= n && y > 0 && y <= m) {
            X = x , Y = y;
            if (s[X][Y] == '*' && !f[X][Y])
                res.push_back(make_pair(X , Y));
            f[X][Y] = 1;
        }
    }
}

void solve(int t , char A , char B) {
    for (int i = 0 ; i < L[t] ; ++ i) {
        if (fun[t][i] == 'L' || fun[t][i] == 'R' || fun[t][i] == 'C')
            work(fun[t][i]);
        else if (fun[t][i] == var[t][0])
            work(A);
        else if (fun[t][i] == var[t][1])
            work(B);
        else {
            assert(islower(fun[t][i]));
            int x = fun[t][i] - 'a';
            if (num[x] == 0) {
                solve(x , -1 , -1);
                i += 2;
            } else if (num[x] == 1) {
                int p1 = -1;
                if (fun[t][i + 2] == var[t][0])
                    p1 = A;
                else if (fun[t][i + 2] == var[t][1])
                    p1 = B;
                else
                    p1 = fun[t][i + 2];
                solve(x , p1 , -1);
                i += 3;
            } else {
                int p1 = -1 , p2 = -1;
                if (fun[t][i + 2] == var[t][0])
                    p1 = A;
                else if (fun[t][i + 2] == var[t][1])
                    p1 = B;
                else
                    p1 = fun[t][i + 2];
                if (fun[t][i + 4] == var[t][0])
                    p2 = A;
                else if (fun[t][i + 4] == var[t][1])
                    p2 = B;
                else
                    p2 = fun[t][i + 4];
                solve(x , p1 , p2);
                i += 5;
            }
        }


    }

}

int main(){
    //freopen("1.txt","r",stdin);
    int i , j;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%s" , s[i] + 1);
    }
    char c;

    while (1) {
        c = getchar();
        if (!~c) break;
        if (c == ' ' || c == '\n' || c == '\r')
            continue;
        //putchar(c);
        str[l ++] = c;
    }
    //puts("");
    i = 0;
    while (i < l) {
        c = str[i ++];
        if (islower(c)) {
            int x = c - 'a';
            assert(str[i ++] == '(');
            while (1) {
                c = str[i ++];
                if (c == ',') continue;
                if (c == ')') break;
                var[x][num[x] ++] = c;
            }
            assert(str[i ++] == '{');
            while (1) {
                c = str[i ++];
                if (c == '}')
                    break;
                fun[x][L[x] ++]= c;
            }
        }
    }
    //for (i = 0 ; i < 26 ; ++ i) {
    //    printf("%c : %s %s\n" , 'a' + i , var[i] , fun[i]);
    //}
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j)
            if (s[i][j] == 'R')
                X = i , Y = j;
    f[X][Y] = 1;
    solve('m' - 'a' , -1 , -1);
    printf("%d\n" , res.size());
    for (i = 0 ; i < res.size() ; ++ i) {
        printf("%d %d\n" , res[i].first , res[i].second);
    }
    return 0;
}
