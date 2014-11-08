import java.util.*;
import java.io.*;
import java.math.*;

public class C {
	static final BigInteger minus1 = BigInteger.valueOf(-1);
	static final BigInteger zero = BigInteger.ZERO;
	static final BigInteger one = BigInteger.ONE;
	static final BigInteger two = BigInteger.valueOf(2);
	static Scanner sc;
	static PrintWriter pw;
	static BigInteger sqrt(BigInteger n) {
		if (n.compareTo(zero) < 0) return minus1;
		BigInteger l = zero, r = n.add(one);
		while (l.add(one).compareTo(r) < 0) {
			BigInteger m = l.add(r).divide(two);
			if (m.multiply(m).compareTo(n) <= 0) l = m;
			else r = m;
		}
		if (l.multiply(l).compareTo(n) != 0) return minus1;
		return l;
	}
	static boolean solve() {
		BigInteger g;
		BigInteger P = sc.nextBigInteger();
		BigInteger Q = sc.nextBigInteger();
		BigInteger U = sc.nextBigInteger();
		BigInteger V = sc.nextBigInteger();
		if (P.abs().compareTo(Q) >= 0 || U.abs().compareTo(V) >= 0) return false;
		if (P.compareTo(zero) <= 0 && U.compareTo(zero) <= 0) return false;
		g = P.gcd(Q); if (!g.equals(zero)) { P = P.divide(g); Q = Q.divide(g); }
		g = U.gcd(V); if (!g.equals(zero)) { U = U.divide(g); V = V.divide(g); }
		BigInteger D = Q.multiply(Q).subtract(P.multiply(P));
		BigInteger E = V.multiply(V).subtract(U.multiply(U));
		g = D.gcd(E); if (!g.equals(zero)) { D = D.divide(g); E = E.divide(g); }
		D = sqrt(D); E = sqrt(E);
		if (D.equals(minus1) || E.equals(minus1)) return false;
		BigInteger A = D.multiply(V);
		BigInteger B = E.multiply(Q);
		g = A.gcd(B); if (!g.equals(zero)) { A = A.divide(g); B = B.divide(g); }
		BigInteger alpha = P.multiply(E);
		BigInteger beta  = U.multiply(D);
		BigInteger gamma = B.multiply(B).subtract(A.multiply(A));
		BigInteger F, G;
		if (gamma.equals(zero)) {
			F = P.multiply(two);
			G = Q;
		} else {
			F = alpha.add(beta).multiply(gamma);
			G = alpha.subtract(beta);
			if (G.compareTo(zero) < 0) { F = F.negate(); G = G.negate(); }
			g = F.gcd(G); if (!g.equals(zero)) { F = F.divide(g); G = G.divide(g); }
			F = sqrt(F);
			G = sqrt(G);
		}
		if (F.equals(minus1) || G.equals(minus1)) return false;
		BigInteger a = G.multiply(A);
		BigInteger b = G.multiply(B);
		BigInteger c = F;
		g = a.gcd(b).gcd(c);
		if (!g.equals(zero)) { a = a.divide(g); b = b.divide(g); c = c.divide(g); }
		BigInteger p = b.multiply(b).add(c.multiply(c)).subtract(a.multiply(a));
		BigInteger q = two.multiply(b).multiply(c);
		BigInteger u = a.multiply(a).add(c.multiply(c)).subtract(b.multiply(b));
		BigInteger v = two.multiply(a).multiply(c);
		if (!P.multiply(q).equals(p.multiply(Q)) || !U.multiply(v).equals(u.multiply(V))) {
			return false;
		}
		if (a.compareTo(b) > 0) { g = a; a = b; b = g; }
		if (a.compareTo(c) > 0) { g = a; a = c; c = g; }
		if (b.compareTo(c) > 0) { g = b; b = c; c = g; }
		if (a.add(b).compareTo(c) <= 0) return false;
		pw.println(a + " " + b + " " + c);
		return true;
	}
	public static void main(String args[]) {
		sc = new Scanner(System.in);
		pw = new PrintWriter(System.out);
		if (!solve()) pw.println(-1);
		sc.close();
		pw.close();
	}
};

