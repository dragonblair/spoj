import java.util.ArrayList;
import java.util.Scanner;


class Main {
	static final int sieve = 1000000;
	static int[] primes = new int[sieve];
	static boolean[] isprime = new boolean[sieve];
	static ArrayList<Integer> actPrimes = new ArrayList<Integer>();
	public static void main(String[] args){
		calcPrimes();
		int t;
		long n;
		Scanner sc = new Scanner(System.in);
		t = sc.nextInt();
		outer:for(int l = 0; l < t; l++){
			int flag = 0;
			n = sc.nextLong();
			System.out.println(letsdoIt(n));
			
			
		}
		
	}
	public static String letsdoIt(long n){
		if(n == 1 || n == 2){
			return "Yes";
		}
			
		//System.out.println("Scanned long");
		for(int i = 0 ; i < actPrimes.size(); i++){
			if(n % actPrimes.get(i) == 0){
				int count = 0;
				while(n % actPrimes.get(i) == 0 && n != 0){
					++count;
					//counter.put(actPrimes.get(i), count);
					//System.out.println("incrementing count for prime fact " + actPrimes.get(i)  + ":" + count + " times");
					n /= actPrimes.get(i);
					}if((actPrimes.get(i) - 3 ) % 4 == 0 && (count % 2 != 0)){
						return "No";
					}}}
		if( n > 1 && ((n - 3) % 4 == 0))
			return "No";
		return "Yes";
	}
	public static void calcPrimes(){
		for(int i = 2; i< sieve; i++)
			primes[i] = i;
		for(int i = 2; i * i < sieve; i++){
			if(!isprime[i]){
				for(int j = i*i ; j < sieve; j += i)
					{
						isprime[j] = true;
						
					}
			}
		}
		for(int i = 2; i < sieve; i++){
			if(!isprime[i])
				actPrimes.add(primes[i]);
		}
	}
	
}
