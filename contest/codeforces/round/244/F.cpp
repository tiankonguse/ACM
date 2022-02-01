// 图为 n 个点， m 条边。
int N,M;

// E[] 和 head, ecnt 使用边表储存有向图
struct edge {
    int from,to,next;
} E[MAXN];
int head[MAXN],ecnt;

// 如果在同一个联通分支里的点的 Belong 指向同一个数字
int Belong[MAXN];

// 辅助数组 以及变量
int Low[MAXN],DFN[MAXN],Stack[MAXN];
int Index,top;
bool Instack[MAXN];


// num[] 和 scc 为 联通分支的个数以及每个联通分支的大小
int num[MAXN],scc;

//用于向边表中插入一条有向边
void Insert(int from,int to) {
    E[ecnt].from=from;
    E[ecnt].to=to;
    E[ecnt].next=head[from];
    head[from]=ecnt++;
}


// 求u 出发可以找到的联通分支。
void Tarjan(int u) {
    int i,v;
    Low[u]=DFN[u]=++Index;
    Stack[++top]=u;
    Instack[u]=true;
    for(i=head[u]; i!=-1; i=E[i].next) {
        v=E[i].to;
        if(!DFN[v]) {
        	// 没有形成环，继续深搜
            Tarjan(v);
            if(Low[u]>Low[v]){
            	//如果 u 大于  v, 说明 v 的某个儿子可以到达v的一个祖先，且这个祖先也是 u 的祖先。
            	//那么把 u 的标记为那个临时祖先。
				Low[u]=Low[v];
            }

        } else if(Instack[v] && Low[u]>DFN[v]) {
        	// 找到一个环， v 是 u 的一个祖先
        	// u 的 临时祖先标记为 v.
            Low[u]=DFN[v];
        }

    }
    if(Low[u]==DFN[u]) {
    	//能够到达这里，说明 u 是一个祖先了。
    	//而且 Stack 中 u 之后的都是 u 的儿子，且可以互相到达。
        scc++;
        do {
            v=Stack[top--];
            Instack[v]=false;
            Belong[v]=scc;
            num[scc]++;
        } while(u!=v);
    }
    return;
}

void Init() {
    memset(head,-1,sizeof(head));
}

void Solve() {
    memset(num,0,sizeof(num));
    memset(DFN,0,sizeof(DFN));
    memset(Instack,false,sizeof(Instack));
    memset(Low,0,sizeof(Low));
    Index=scc=top=0;
    for(int  i=1; i<=N; i++) { //缩点
        if(!DFN[i]) Tarjan(i);
    }
}

