import java.util.*;
public class NY10A{

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int p;

		p = sc.nextInt();

		while(p-- != 0){
			int n;String s;
			int[] count = new int[8];
			n = sc.nextInt();
			s = sc.next();
			for (int i = 0;  i < s.length() - 2; ++i ) {
				String sub = s.substring(i,i+3);
				if(sub.equals("TTT"))
					count[0]++;
				else if(sub.equals("TTH"))
					count[1]++;
				else if(sub.equals("THT"))
					count[2]++;
				else if(sub.equals("THH"))
					count[3]++;
				else if(sub.equals("HTT"))
					count[4]++;
				else if(sub.equals("HTH"))
					count[5]++;
				else if(sub.equals("HHT"))
					count[6]++;
				else
					count[7]++;
			}
			System.out.print( n + " ");
			for(int f : count)
				System.out.print( f + " ");
			System.out.println();	
		}
	}
}