import java.io.*;
import java.math.*;
import java.util.*;

public class H {
	static final int N = 405;
	static final String FILE = "poker";
	public static void main(String args[]) throws IOException {
		Scanner in = new Scanner(new File(FILE + ".in"));
		PrintWriter out = new PrintWriter(new File(FILE + ".out"));
		BigInteger c[][] = new BigInteger[N][N];
		c[0][0] = BigInteger.ONE;
		for (int i = 1; i < N; ++i) {
			c[i][0] = c[i][i] = BigInteger.ONE;
			for (int j = 1; j < i; ++j) {
				c[i][j] = c[i - 1][j - 1].add(c[i - 1][j]);
			}
		}
		for (int cas = 0; ; ++cas) {
			int r = in.nextInt();
			int s = in.nextInt();
			int a = in.nextInt();
			int b = in.nextInt();
			if (r == 0 && s == 0 && a == 0 && b == 0) break;
			if (cas > 0) out.println();
			BigInteger sum = c[r * s][a];
			BigInteger f[][] = new BigInteger[s + 1][a + 1];
			for (int i = 0; i <= s; ++i) {
				for (int j = 0; j <= a; ++j) {
					f[i][j] = BigInteger.ZERO;
				}
			}
			f[0][0] = BigInteger.ONE;
			for (int i = 0; i < s; ++i) {
				for (int j = 0; j <= a; ++j) {
					for (int k = 0; k < b && k <= r && j + k <= a; ++k) {
						f[i + 1][j + k] = f[i + 1][j + k].add(f[i][j].multiply(c[r][k]));
					}
				}
			}
			BigInteger ansf = sum.subtract(f[s][a]);
			BigInteger g[][][] = new BigInteger[r + 1][b][a + 1];
			for (int i = 0; i <= r; ++i) {
				for (int j = 0; j < b; ++j) {
					for (int k = 0; k <= a; ++k) {
						g[i][j][k] = BigInteger.ZERO;
					}
				}
			}
			g[0][0][0] = BigInteger.ONE;
			for (int i = 0; i < r; ++i) {
				for (int j = 0; j < b; ++j) {
					for (int k = 0; k <= a; ++k) {
						g[i + 1][0][k] = g[i + 1][0][k].add(g[i][j][k]);
						if (j + 1 == b) continue;
						for (int t = 1; t <= s && k + t <= a; ++t) {
							g[i + 1][j + 1][k + t] = g[i + 1][j + 1][k + t].add(g[i][j][k].multiply(c[s][t]));
						}
					}
				}
			}
			BigInteger anss = BigInteger.ZERO;
			for (int i = 0; i < b; ++i) {
				anss = anss.add(g[r][i][a]);
			}
			anss = sum.subtract(anss);
			BigInteger gf = sum.gcd(ansf);
			BigInteger gs = sum.gcd(anss);
			out.println(anss.divide(gs) + "/" + sum.divide(gs));
			out.println(ansf.divide(gf) + "/" + sum.divide(gf));
		}
		in.close();
		out.close();
	}
}
