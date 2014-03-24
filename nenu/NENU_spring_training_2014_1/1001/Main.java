/*************************************************************************
    > File Name: 1001.java
    > Author: tiankonguse
    > Mail: i@tiankonguse.com 
    > Created Time: Mon 03 Mar 2014 07:59:01 PM CST
 ************************************************************************/
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
public static void main(String[] args) {
BigInteger a,b;
Scanner cin = new Scanner(System.in);
while (cin.hasNextBigInteger()) {
a = cin.nextBigInteger();
b = cin.nextBigInteger();
System.out.println(a.add(b).toString());
}
}
}

