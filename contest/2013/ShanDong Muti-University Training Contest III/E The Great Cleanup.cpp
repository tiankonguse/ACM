/*************************************************************************
    > File Name: E The Great Cleanup.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/16 21:45:49
 ************************************************************************/

#include<cstdio>
#include<cstring>

const int N = 1010;
char rem[N][22];
int map[256];
int ans;
int pos;
struct T {
    T* next[70];
    bool del;
    void init(bool _del) {
        del = _del;
        memset(next,NULL,sizeof(next));
    }
} str[N*300],*root;


void insert(char *p) {
    T* pre = root;
    while(*p){
        if(pre->next[map[*p]] == NULL) {
            str[pos].init(false);
            pre->next[map[*p]] = str+pos;
            pos++;
        }
        pre = pre->next[map[*p]];
        p++;
    }
}

void del(char*p) {
    T* pre = root;
    while(*p) {
        if(pre->del)return;
        if(pre->next[map[*p]] == NULL) {
            str[pos].init(true);
            pre->next[map[*p]] = str+pos;
            pos++;
            ans++;
            return;
        }
        pre = pre->next[map[*p]];
        if(pre->del)return;
        p++;
    }
    ans++;
}

int main() {
    char tmp[30];
    int cas,n1,n2,i;
    int k=0;
    for(i='A'; i<='Z'; i++) {
        map[i] = k++;
    }
    for(i='a'; i<='z'; i++) {
        map[i] = k++;
    }
    for(i='0'; i<='9'; i++) {
        map[i] = k++;
    }
    map['.'] = k++;

    scanf("%d",&cas);
    while(cas--) {

        ans = 0;
        pos = 1;
        root = str;
        root->init(false);

        scanf("%d",&n1);
        for(i=0; i<n1; i++) {
            scanf("%s",rem[i]);
        }

        scanf("%d",&n2);
        for(i=0; i<n2; i++) {
            scanf("%s",tmp);
            insert(tmp);
        }

        if(n2==0) {
            printf("1\n");
            continue;
        }

        for(i=0; i<n1; i++) {
            del(rem[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
