// 并查集 By 猛犸也钻地 @ 2011.11.24

/* 经典并查集题目模型 //
奇偶异或：
   建立2n个结点，每个元素拥有两个结点，表示是0还是1
   如果A^B为0，把A0和B0，A1和B1连接，反之则把A0和B1，A1和B0连接
   这表示那两个元素的值必须同时出现或者不出现(思想上类似于2SAT)
   如果A0和A1在连接后属于同一集合，那么就出现了矛盾
   记最终集合的总数为m，则方案数是2^(m/2)
食物链/石头剪刀布：
   同上，只不过根据食物链的循环长度k要建立kn个结点，方案数也是k^(m/k)
朋友敌人：
   由于规则：敌人的敌人就是朋友。因此对于某个人
   他的敌人们总是在同一个朋友集合内，记录每个人的敌人e[]即可处理：
   if(~e[x]) link(e[x],y); else e[x]=y;
   if(~e[y]) link(e[y],x); else e[y]=x;
   注意，敌人关系不能通过朋友关系传递，即敌人的朋友的敌人可能不是一伙的
// 要维护并查集内具体元素时，可以把sz[]改成某种集合结构，如set */

class DSet {
public:
    static const int SIZE = 1000005;
    int sz[SIZE],p[SIZE];
    // 将[0,n-1]范围内的元素初始化，每个元素独自成为一个集合
    void init(int n){
        for(int i=0;i<n;i+=sz[p[i]=i]=1);
    }
    // 查询x所在集合的根结点
    int root(int x){
        return p[x]!=x?p[x]=root(p[x]):x;
    }
    // 将x和y所在的集合合并，若合并前x和y已经在同一个集合，则返回false
    bool join(int x, int y){
        x=root(x),y=root(y);
        if(x==y) return false;
        if(sz[x]<=sz[y]) sz[p[x]=y]+=sz[x];
                    else sz[p[y]=x]+=sz[y];
        return true;
    }
};
