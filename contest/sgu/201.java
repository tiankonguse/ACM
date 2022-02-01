import java.util.*;  
import java.io.*;  
import java.math.*;  

public class Solution {  
    public static void main(String[] args) {  
        InputStream inputStream = System.in;  
        OutputStream outputStream = System.out;  
        InputReader in = new InputReader(inputStream);  
        PrintWriter out = new PrintWriter(outputStream);  
        Task solver = new Task();  
        solver.solve(in, out);  
        out.close();  
    }  
}  

class Task {  
    static int go[][]=new int [1005][26];  
    static boolean end[]=new boolean [1005];  
    static int x[][]=new int [1005][26];  
    static int to[][]=new int [1005][26];  
    int dfs(int now,int ch){  
        if(x[now][ch]==0){  
            return to[now][ch]=go[now][ch];  
        }  
        if(to[now][ch]!=-1)   
            return to[now][ch];  
        to[now][ch]=0;  
        return to[now][ch]=dfs(go[now][ch],ch);  
    }  
    void solve(InputReader in,PrintWriter out){  
        String S=in.nextLine();  
        int m=S.length();  
        int n=in.nextInt();  
        int s=in.nextInt();  
        int endcnt=in.nextInt();  
        for(int i=1;i<=n;i++)  
            end[i]=false;  
        for(int i=0;i<endcnt;i++){  
            int u=in.nextInt();  
            end[u]=true;  
        }  
        for(int i=1;i<=n;i++){  
            for(int j=0;j<m;j++)  
                go[i][j]=in.nextInt();  
        }  
        for(int i=1;i<=n;i++){  
            for(int j=0;j<m;j++){  
                x[i][j]=in.nextInt();  
                to[i][j]=-1;  
            }  
        }  
        for(int i=1;i<=n;i++){  
            for(int j=0;j<m;j++){  
                dfs(i,j);  
            }  
        }  
        int l=in.nextInt();  
        BigInteger dp[][]=new BigInteger [65][1005];  
        for(int i=0;i<=l;i++)  
            for(int j=1;j<=n;j++)  
                dp[i][j]=BigInteger.ZERO;  
        dp[0][s]=BigInteger.ONE;  
        for(int i=1;i<=l;i++){  
            for(int j=1;j<=n;j++){  
                for(int k=0;k<m;k++){  
                    if(to[j][k]>0)  
                        dp[i][to[j][k]]=dp[i][to[j][k]].add(dp[i-1][j]);  
                }  
            }  
        }  
        BigInteger ans=BigInteger.ZERO;  
        for(int i=1;i<=n;i++)  
            if(end[i])  
                ans=ans.add(dp[l][i]);  
        out.println(ans);  
    }  
}  
class InputReader {  
    public BufferedReader reader;  
    public StringTokenizer tokenizer;  
  
    public InputReader(InputStream stream) {  
        reader = new BufferedReader(new InputStreamReader(stream));  
        tokenizer = null;  
    }  
    public String nextLine() {  
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {  
            try {  
                tokenizer = new StringTokenizer(reader.readLine());  
            } catch (IOException e) {  
                throw new RuntimeException(e);  
            }  
        }  
        return tokenizer.nextToken();  
    }  
  
    public int nextInt() {  
        return Integer.parseInt(nextLine());  
    }  
}  
