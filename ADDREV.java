import java.util.Scanner;


class Main {
public static void main(String[] args){
	Scanner sc  = new Scanner(System.in);
	int n;
	n = sc.nextInt();
	String s1 = new String();
	String s2 = new String();
	String s3 = new String();
	StringBuffer s4,s5;
	
	for(int i = 1; i <= n; i++){
		s1 = sc.next();
		s2 = sc.next();
		s4 = new StringBuffer(s1);
		s5 = new StringBuffer(s2);
		s1 = s4.reverse().toString();
		s2 = s5.reverse().toString();
		Long r = (Long.parseLong(s1) + Long.parseLong(s2));
		s4 = new StringBuffer(r.toString());
		s4 = s4.reverse();
		int k = -1;
		while(s4.charAt(++k) == '0');
			
		
		s1 = s4.substring(k);
		System.out.println(s1);
		
	}
}
}
