import java.math.BigInteger;
import java.util.Scanner;

public class Solution {
	static BigInteger dp[][][][] = new BigInteger[2][2][2][10010];
	static boolean vis[][][][] = new boolean[2][2][2][10010];
	static int a[] = new int[10010];
	static String s;
	static Scanner cin = new Scanner(System.in);
	static void dfs(int l, int r, int fix, int li, int ri) {
		if (vis[fix][li][ri][l]) return;
		vis[fix][li][ri][l] = true;
		if (l > r) {
			if (li == ri) dp[fix][li][ri][l] = BigInteger.ONE;
			return;
		}
		dp[fix][li][ri][l] = BigInteger.ZERO;
		if (l == r) {
			for (int i = 0; i < 10; ++i) {
				if (i + i + ri == a[l] + li * 10) 
					dp[fix][li][ri][l] = dp[fix][li][ri][l].add(BigInteger.ONE);
			}
			return;
		}
		for (int i = 0; i < 10; ++i) for (int j = 0; j < 2; ++j) {
			if (l == 0 && i == 0) continue;
			if (fix == 0 && l == 1 && i == 0) continue;
			int la = a[l] + li * 10 - j - i; if (la < 0 || la >= 10) continue;
			int lb = i + la + ri;
			int k = 0; 
			if (lb >= 10) {
				lb -= 10; 
				k = 1;
			}
			if (lb == a[r]) {
				dfs(l + 1, r - 1, fix, j, k);
				dp[fix][li][ri][l] = dp[fix][li][ri][l].add(dp[fix][j][k][l + 1]);
			}
		}
		return;
	}
	public static void main(String[] args) {
		while (cin.hasNext()) {
			s = cin.next();
			if (s.equals("0")) break;
			int n = s.length();
			for (int i = 0; i < n; ++i) {
				int t = 0;
				for (int j = i; j < n; ++j) a[t++] = s.charAt(j) - '0';
				n = t;
				break;
			}
			for (int i = 0; i < 2; ++i) 
				for (int j = 0; j < 2; ++j) 
					for (int k = 0; k < 2; ++k)
						for (int l = 0; l <= n; ++l) {
							dp[i][j][k][l] = BigInteger.ZERO;
							vis[i][j][k][l] = false;
						}
			dfs(0, n - 1, 1, 0, 0);
			BigInteger ret = dp[1][0][0][0];
			if (a[0] == 1) {
				dfs(1, n - 1, 0, 1, 0);
				ret = ret.add(dp[0][1][0][1]);
			}
			System.out.println(ret);
		}
	}
}
