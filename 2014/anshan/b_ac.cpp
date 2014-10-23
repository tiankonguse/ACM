#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<map>

#define LL long long
#define CLR(a, b) memset(a, b, sizeof(a))
using namespace std;

const int maxn = 11000;

map<int, int> mp, re;
int L[maxn], R[maxn], top, tot;
LL val[maxn];

void init() {
    CLR(val, -1);
    R[0] = 1;
    L[1] = 0;
    mp.clear();
    re.clear();
    tot = 2;
    top = -1;
}

void Addv(int u, int rig) {
    R[L[rig]] = u;
    L[u] = L[rig];
    R[u] = rig;
    L[rig] = u;
}

void Remov(int u) {
    int lft = L[u];
    int rig = R[u];
    R[lft] = rig;
    L[rig] = lft;
}

bool Add(int u) {
    if(mp.count(u) && val[mp[u]] != -1) return false;
    if(!mp.count(u)) mp[u] = tot ++, re[tot - 1] = u;
    Addv(mp[u], 1);
    val[mp[u]] = 0;
    return true;
}

bool Close(int u) {
    if(!mp.count(u) || val[mp[u]] == -1) return false;
    if(top == mp[u]) {
        if(val[mp[u]]) printf("Bye %d: %lld\n", u, val[mp[u]]);
        top = -1;
    } else if(mp[u] == R[0]) {
        if(val[mp[u]]) printf("Bye %d: %lld\n", u, val[mp[u]]);
    }
    Remov(mp[u]);
    return true;
}

bool Chat(int x) {
    if(L[1] == 0) return false;
    if(top != -1) val[top] += x;
    else val[R[0]] += x;
    return true;
}

bool Rotate(int x) {
    if(x <= 0) return false;
    int cnt = 0, now = R[0];
    while(now != 1) {
        cnt ++;
        if(cnt == x) break;
        now = R[now];
    }
    if(cnt != x) return false;
    Remov(now);
    Addv(now, R[0]);
    return true;
}

bool Prior() {
    if(L[1] == 0) return false;
    int now = R[0], idx = -1;
    while(now != 1) {
        idx = max(idx, re[now]);
        now = R[now];
    }
    now = mp[idx];
    Remov(now);
    Addv(now, R[0]);
    return true;
}

bool Choose(int u) {
    if(!mp.count(u) || val[mp[u]] == -1) return false;
    Remov(mp[u]);
    Addv(mp[u], R[0]);
    return true;
}

bool Top(int u) {
    if(!mp.count(u) || val[mp[u]] == -1) return false;
    top = mp[u];
    return true;
}

bool Untop() {
    if(top == -1) return false;
    top = -1;
    return true;
}

int main() {
    int T, n;
    scanf("%d", &T);
    while(T --) {
        init();
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++) {
            printf("Operation #%d: ", i);
            char op[20];
            int u;
            scanf("%s", op);
            if(strcmp(op, "Add") == 0) {
                scanf("%d", &u);
                if(Add(u)) puts("success.");
                else puts("same priority.");
            } else if(strcmp(op, "Close") == 0) {
                scanf("%d", &u);
                if(Close(u)) {
                    printf("close %d with %lld.\n", u, val[mp[u]]);
                    val[mp[u]] = -1;
                } else puts("invalid priority.");
            } else if(strcmp(op, "Chat") == 0) {
                scanf("%d", &u);
                if(Chat(u)) puts("success.");
                else puts("empty.");
            } else if(strcmp(op, "Rotate") == 0) {
                scanf("%d", &u);
                if(Rotate(u)) puts("success.");
                else puts("out of range.");
            } else if(strcmp(op, "Prior") == 0) {
                if(Prior()) puts("success.");
                else puts("empty.");
            } else if(strcmp(op, "Choose") == 0) {
                scanf("%d", &u);
                if(Choose(u)) puts("success.");
                else puts("invalid priority.");
            } else if(strcmp(op, "Top") == 0) {
                scanf("%d", &u);
                if(Top(u)) puts("success.");
                else puts("invalid priority.");
            } else if(strcmp(op, "Untop") == 0) {
                if(Untop()) puts("success.");
                else puts("no such person.");
            }
        }

        if(top != -1) {
            if(val[top]) printf("Bye %d: %lld\n", re[top], val[top]);
            val[top] = 0;
        }

        int now = R[0];
        while(now != 1) {
            if(val[now]) printf("Bye %d: %lld\n", re[now], val[now]);
            now = R[now];
        }
    }
    return 0;
}
