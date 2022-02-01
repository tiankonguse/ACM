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
	int f[] , cnt;
	int getf(int x) {
		if (x == f[x])
			return x;
		return f[x] = getf(f[x]);
	}
	void merge(int x , int y) {
		x = getf(x) ; y = getf(y);
		if (x == y) return;
		f[x] = y ;
		-- cnt;
	}
	void solve(InputReader in,PrintWriter out) {  
		int n , m , S;
		n = in.nextInt();
		m = in.nextInt();
		S = n * m;
		BigInteger power[] = new BigInteger[n * m + 1];
		power[0] = BigInteger.ONE;
		for (int i = 1 ; i <= n * m ; ++ i)
			power[i] = power[i - 1].add(power[i - 1]);
		BigInteger ans = BigInteger.ZERO;
		if (n != m) {
			
			for (int k = 0 ; k < 2 ; ++ k) {
				for (int i = 0 ; i < n ; ++ i) {
					for (int j = 0 ; j < m ; ++ j) {
						f = new int[S];
						for (int l = 0 ; l < S ; ++ l)
							f[l] = l;
						cnt = S;
						for (int l = 0 ; l < S ; ++ l) {
							int x = l / m , y = l % m;
							x = (x + i) % n ; y = (y + j) % m;
							if (k == 1) {
								x = n - x - 1;
								y = m - y - 1;
							}
							merge(l , x * m + y);
						}
						ans = ans.add(power[cnt]);
					}
				}
			}
			ans = ans.divide(BigInteger.valueOf(S * 2));
		} else {
			for (int r = 0 ; r < 2 ; ++ r) {
				for (int k = 0 ; k < 2 ; ++ k) {
					for (int i = 0 ; i < n ; ++ i) {
						for (int j = 0 ; j < m ; ++ j) {
							f = new int[S];
							for (int l = 0 ; l < S ; ++ l)
								f[l] = l;
							cnt = S;
							for (int l = 0 ; l < S ; ++ l) {
								int x = l / m , y = l % m;
								x = (x + i) % n ; y = (y + j) % m;
								if (r == 1) {
									int tmp = y;
									y = n - x - 1;
									x = tmp;	
								}
								if (k == 1) {
									x = n - x - 1;
									y = m - y - 1;
								}
								merge(l , x * m + y);
							}
							ans = ans.add(power[cnt]);
						}
					}
				}
			}
			ans = ans.divide(BigInteger.valueOf(S * 4));
		}
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
