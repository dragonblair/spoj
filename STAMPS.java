/* 
* @Author: Krishna Kalubandi
* @Date:   2015-06-20 11:25:55
* @Last Modified by:   Krishna Kalubandi
* @Last Modified time: 2015-06-20 12:01:07
*/

import java.util.*;
import java.io.*;

class Main {
	final int n = 1000000;
    public static void main(String[] args) {

    	Scanner sc = new Scanner(System.in);

    	int t = sc.nextInt();

    	for (int i = 0; i < t ; ++i )
    		
    	
    	{
    		int s,n;
    		s = sc.nextInt();
    		n = sc.nextInt();

    		ArrayList<Integer> friends = new ArrayList<Integer>();
    		for (int j = 0; j < n ;j++) {
    			friends.add(sc.nextInt());
    		}
    		System.out.println("Scenario #" + (i+1) + ":");
    		Collections.sort(friends);
    		Collections.reverse(friends);
    		int count = 0;
    		int f = 0;
    		long sum = 0;
    		while(f < n && (sum < s)){ sum += friends.get(f++); count++; }

    		if(f == n)
    			System.out.println("impossible");
    		else
    			System.out.println(count);
    		if(i != t-1)
    		System.out.println();
    	}
    }
}