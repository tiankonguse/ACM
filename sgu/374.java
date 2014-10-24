import java.util.Arrays;
import java.util.Scanner;
import java.math.BigInteger;

public class Solution {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int a , b , k;
		a = cin.nextInt();
		b = cin.nextInt();
		k = cin.nextInt();
		a += b;
		BigInteger res = BigInteger.ONE;
		for (int i = 0 ; i < k ; ++ i)
			res = res.multiply(BigInteger.valueOf(a));
		System.out.println(res);
	}
}

