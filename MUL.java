import java.math.BigInteger;
import java.util.Scanner;


public class Main {

	public static void main(String args[]){
		String s1,s2;
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for(int i = 1; i <= n; i++)
		{
			s1 = sc.next();
			s2 = sc.next();
			BigInteger big1 = new BigInteger(s1);
			BigInteger big2 = new BigInteger(s2);
			System.out.println(big1.multiply(big2));
		}
	}
}
