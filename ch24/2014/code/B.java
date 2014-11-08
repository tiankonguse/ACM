import java.io.*;
import java.util.*;
import java.math.*;


public class B {
    static final int N = 1005;
    static final int M = 10005;
    static final int SC = 200;
    class Edges  
    {  
        int a,b,c;  
    } 
    Edges edge[] = new Edges[M];
    Edges tmpe[] = new Edges[M];  
      
    int n,m;   
    int f[] = new int [N];
    int U[] = new int [N];
    int vist[] = new int[N];//f,U都是并查集，U是每组边临时使用  
    int G[][] = new int[N][N];
    BigDecimal C[][] = new BigDecimal [N][N];//G顶点之间的关系，C为生成树计数用的Kirchhoff矩阵  
    BigDecimal ans;
      
    ArrayList <ArrayList <Integer> > V;//记录每个连通分量  

    {
        for (int i = 0; i < M; i++)
            edge[i] = tmpe[i] = new Edges();
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                C[i][j] = BigDecimal.ZERO.setScale(SC, BigDecimal.ROUND_HALF_UP);
        ans = BigDecimal.ZERO.setScale(SC, BigDecimal.ROUND_HALF_UP);
    }
      
    int Find(int x, int f[])  
    {  
        if(x==f[x])  
            return x;  
        else  
            return Find(f[x],f);  
    }  

    BigDecimal sabs(BigDecimal v){
        return v.abs();
    }

      
    BigDecimal det(BigDecimal a[][],int n)//生成树计数:Matrix-Tree定理  
    {  
        for(int i=0; i<n; i++)  
            for(int j=0; j<n; j++)  
                a[i][j] = a[i][j].setScale(SC, BigDecimal.ROUND_HALF_UP);
        BigDecimal ret= BigDecimal.ONE; 
        /*
        for (int k = 1; k < n; k++) {
            for (int i = k + 1; i < n; i++) if (sabs(a[i][k]).compareTo(sabs(a[k][k])) > 0) {
                for (int j = k; j < n; j++) {
                    BigDecimal t = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = t;
                }
                ret = ret.negate();
            }
            if (sabs(a[k][k]).compareTo(BigDecimal.valueOf(1e-6)) <= 0) return BigDecimal.ZERO;
            ret = ret.multiply(a[k][k]);
            //if (sabs(a[k][k]).compareTo(BigDecimal.valueOf(1e-6)) <= 0) continue;
            for (int i = k + 1; i < n; i++) if (sabs(a[i][k]).compareTo(BigDecimal.valueOf(1e-5)) > 0) {
                BigDecimal mul = a[i][k].divide(a[k][k], SC, BigDecimal.ROUND_HALF_UP);
                for (int j = k; j < n; j++)
                    a[i][j] = a[i][j].subtract(a[k][j].multiply(mul));
            }
        }
        */
        
        for(int i=1; i<n; i++)  
        {  
            for(int j=i+1; j<n; j++)  
                while(sabs(a[j][i]).compareTo(BigDecimal.valueOf(1e-6)) > 0)
                {  
                    BigDecimal t=a[i][i].divide(a[j][i], SC, BigDecimal.ROUND_HALF_UP);  
                    for(int k=i; k<n; k++)  
                        a[i][k]=(a[i][k].subtract(a[j][k].multiply(t)));  
                    for(int k=i; k<n; k++) {
                        t = a[i][k];
                        a[i][k] = a[j][k];
                        a[j][k] = t;
                    }
                    ret = ret.negate();
                }  
            if(a[i][i].equals(BigDecimal.ZERO))  
                return BigDecimal.ZERO;  
            ret=ret.multiply(a[i][i]);  
        } 
        
        //System.out.println("ret = " + ret);
        return ret;  
    }  
      
    void Solve()  
    {  
        for(int i=1; i<=n; i++)//初始化并查集  
        {  
            f[i]=i;  
            vist[i]=0;  
        }  
      
        int Edge=-1;//记录相同的权值的边  
        ans = BigDecimal.ONE;  
        for(int k=0; k<=m; k++)  
        {  
            if(edge[k].c!=Edge||k==m)//一组相等的边,即权值都为Edge的边加完  
            {  
                for(int i=1; i<=n; i++)  
                {  
                    if(vist[i] != 0)  
                    {  
                        int u=Find(i,U);  
                        V.get(u).add(i);  
                        vist[i]=0;  
                    }  
                }  
                for(int i=1; i<=n; i++) //枚举每个连通分量  
                {  
                    if(V.get(i).size()>1)  
                    {  
                        for(int a=1; a<=n; a++)  
                            for(int b=1; b<=n; b++)  
                                C[a][b] = BigDecimal.ZERO;  
                        int len=V.get(i).size();  
                        for(int a=0; a<len; a++) //构建Kirchhoff矩阵C  
                            for(int b=a+1; b<len; b++)  
                            {  
                                int a1=V.get(i).get(a);  
                                int b1=V.get(i).get(b);  
                                C[a][b]=(C[b][a] = C[b][a].subtract(BigDecimal.valueOf(G[a1][b1])));  
                                C[a][a] = C[a][a].add(BigDecimal.valueOf(G[a1][b1]));//连通分量的度  
                                C[b][b] = C[b][b].add(BigDecimal.valueOf(G[a1][b1]));  
                            }  
                        BigDecimal ret= det(C,len);  
                        ans=(ans.multiply(ret));//对V中的每一个连通块求生成树个数再相乘  
                        for(int a=0; a<len; a++)  
                            f[V.get(i).get(a)]=i;  
                    }  
                }  
                for(int i=1; i<=n; i++)  
                {  
                    U[i]=f[i]=Find(i,f);  
                    V.get(i).clear();;  
                }  
                if(k==m)  
                    break;  
                Edge=edge[k].c;  
            }  
      
            int a=edge[k].a;  
            int b=edge[k].b;  
            int a1=Find(a,f);  
            int b1=Find(b,f);  
            if(a1==b1)  
                continue;  
            vist[a1]=vist[b1]=1;  
            U[Find(a1,U)]=Find(b1,U);//并查集操作  
            G[a1][b1]++;  
            G[b1][a1]++;  
        }  
      
        boolean flag=false;  
        for(int i=2; i<=n&& !flag; i++)  
            if(U[i]!=U[i-1])  
                flag= true;  
        if(m==0)  
            flag = true;  
        //printf("%.0lf\n",flag?0:(double)ans);  
        //System.out.println("ans = " + ans);
    }  
      
    B()  
    {  
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        m = in.nextInt();
        V = new ArrayList < ArrayList <Integer> > ();
        for(int i=0; i<=n; i++)  
            V.add(new ArrayList<Integer>());  
        for(int i=0; i<m; i++){ 
            edge[i].a = in.nextInt();
            edge[i].b = in.nextInt(); 
            edge[i].a++;
            edge[i].b++;
            edge[i].c = 1;
            if(i != 0) tmpe[i - 1] = edge[i];
        }
        Solve();  
        BigDecimal x = ans;
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) G[i][j] = 0;
        for(int i = 1; i <= n; ++i)
            V.get(i).clear();
        for(int i = 0; i < m - 1; ++i)
            edge[i] = tmpe[i];
        --m;
        Solve();
        //System.out.println("x = " + x);
        BigDecimal y = ans;
        BigDecimal tttmp = x.subtract(y);
        System.out.printf("%.10f\n", tttmp.divide(x, SC, BigDecimal.ROUND_HALF_UP).doubleValue());
    }  
    public static void main(String[] args) {
        new B();
    }
}