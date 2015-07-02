/* 
* @Author: Krishna Kalubandi
* @Date:   2015-06-30 15:53:00
* @Last Modified by:   Krishna Kalubandi
* @Last Modified time: 2015-06-30 16:26:21
*/

import java.util.*;
import java.io.*;

class Main {
	private static final int seive = 50100;
	static StringBuilder sb = new StringBuilder();
	static boolean isprime[] = new boolean[seive];
	static ArrayList<Integer> primes = new ArrayList<Integer>();
    public static void calcPrimes(){
		for(int i = 2; i * i < seive; i++){
			if(!isprime[i]){
				for(int j = i*i ; j < seive; j += i)
				{
					isprime[j] = true;
				}
			}
		}
		for(int i = 2; i < seive; ++i){
			if(!isprime[i])
				primes.add(i);
		}
	}
    public static void main(String[] args)  throws IOException{

    	calcPrimes();
    	BufferedReader inp = new BufferedReader (new InputStreamReader(System.in));
    	int t = Integer.parseInt(inp.readLine());
    	long m = 1000000007;

    	while(t-- != 0)
    	{
    		int n = Integer.parseInt(inp.readLine());

		long ans = 1;

		for (int i = 0; n/primes.get(i) != 0 ; ++i) {
			int power = 0;
			int prime = primes.get(i);
			int f = prime;
			//System.out.println("Bro prime is "+ prime);
			int count = 1;
			while(n/f != 0){
				power += n/f;
				++count;
				f = (int)Math.pow(prime,count);
			}
			power++;
			//System.out.println("Bro count is "+power);
			ans = (ans * power);
			if(ans > m) ans = ans % m;
    		
    	}
    	System.out.println(ans);
    }
    }
}