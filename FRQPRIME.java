/* 
* @Author: Krishna Kalubandi
* @Date:   2015-06-19 17:13:02
* @Last Modified by:   Krishna Kalubandi
* @Last Modified time: 2015-06-19 18:03:04
*/

import java.util.*;
import java.io.*;


class Main {
	private static final int seive = 100010;
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
    public static void main(String[] args) {
    	calcPrimes();
    	Scanner sc = new Scanner(System.in);

    	int tt = sc.nextInt();

    	while(tt-- != 0)
    	{
    		int n,k;
    		n = sc.nextInt();
    		k = sc.nextInt();
    		int count = 0;
    		for (int i = 0; primes.get(i) <= n ; ++i ){
    			count++;
    		}
    		if(count < k){
    			System.out.println(0);
    		}
    		else if(k == 0){
    			n-= 1;

    			System.out.println( ((long)n * (n + 1)) / 2);
    		}
    		else{
    			long tcount = 0;
    			for (int i = 2; (count >= k) && ( i <= n) ; ++i) {
    				
    				tcount += (long) ( 1 + n - primes.get(k-1));
    				if(!isprime[i])
    					k++;
    			}
    			System.out.println(tcount);
    		}
    	}

    }
}