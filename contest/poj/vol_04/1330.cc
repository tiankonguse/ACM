#include"vector"
#include"cstdio"
#include"cstring"
#define MAXN 10005
using namespace std;
vector<int>tree[MAXN];
bool used[MAXN];
int degree_in[MAXN];
int depth[MAXN];
int path[MAXN];
int N,res;

void dep_dfs(int p,int deep){
    int len=tree[p].size();
    for(int i=0;i<len;i++){
        if(!used[tree[p][i]]){
            used[tree[p][i]]=true;
            depth[tree[p][i]]=deep;
            dep_dfs(tree[p][i],deep+1);
        }
    }
}
bool dfs(int p,int deep,int des){
    if(p==des){
        int min=0x7f7f7f7f;
        for(int i=0;i<deep;i++){
            if(depth[path[i]]<min){
                min=depth[path[i]];
                res=path[i];
            }
        }
        return true;
    }
    else{
        int len=tree[p].size();
        for(int i=0;i<len;i++){
            if(!used[tree[p][i]]){
                used[tree[p][i]]=true;
                path[deep]=tree[p][i];
                if(dfs(tree[p][i],deep+1,des))return true;
            }
        }
    }
    return false;
}

int main(){
    int T,a,b,root;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        memset(degree_in,0,sizeof(degree_in));
        memset(used,false,sizeof(used));
        for(int i=0;i<N;i++)tree[i].clear();
        for(int i=0;i<N-1;i++){
            scanf("%d%d",&a,&b);
            a--;b--;
            tree[a].push_back(b);
            tree[b].push_back(a);
            degree_in[b]++;
        }
        for(int i=0;i<N;i++){
            if(degree_in[i]==0){
                root=i;
                break;
            }
        }
        depth[root]=0;
        used[root]=true;
        dep_dfs(root,1);
        scanf("%d%d",&a,&b);
        a--;b--;
        memset(used,false,sizeof(used));
        path[0]=a;
        used[a]=true;
        res=-1;
        dfs(a,1,b);
        printf("%d\n",res+1);
    }
    return 0;
}
