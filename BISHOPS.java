import java.math.BigInteger;
import java.util.Scanner;


class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stu
		Scanner sc  = new Scanner(System.in);
		BigInteger b1;
		String s;
		int counter = 0;
		while(counter != 1024){
			++counter;
			s = sc.next();
			if(s.equals("1"))
				System.out.println("1");
			else if (s.equals("0"))
				System.out.println("0");
			else
			{
				b1 = new BigInteger(s);
				b1 = b1.multiply(new BigInteger("2")).subtract(new BigInteger("2"));
				System.out.println(b1);
			}
			
		}
		}
			
	}


