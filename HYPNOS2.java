import java.util.*;
class Solution{
	public static void main(String[] args){
		int t;
		Scanner sc = new Scanner(System.in);
		t = sc.nextInt();
		for(int k = 0; k < t; k++){
			long n = sc.nextLong();
			int count = 0;
		while(n / 10 != 0){
			++count;
			long sum = 0;
			long copy = n;
			while(copy != 0){
				long cur = copy % 10;
				sum += cur * cur;
				copy /= 10;
			}
			n = sum;
		}
		if(n == 1)
			System.out.println(count);
		else if(n == 7)
			System.out.println(count+5);
		else
			System.out.println(-1);
	}
}
}