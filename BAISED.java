/* 
* @Author: Krishna Kalubandi
* @Date:   2015-06-22 11:16:40
* @Last Modified by:   Krishna Kalubandi
* @Last Modified time: 2015-06-22 11:38:18
*/

import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) {

    	Scanner sc = new Scanner(System.in);

    	long t = sc.nextLong();

    	while(t-- != 0){
    		long n = sc.nextLong();
    		String s;
    		HashSet<Long> set = new HashSet<Long>();
    		long badness = 0;
    		for (int i = 0; i < n ; ++i ) {
    			s = sc.next();
    			long cur = sc.nextLong();
    			if(set.contains(cur)){
    				while((set.contains(cur)))
    				{
    					++cur; ++badness;
    				}
    			}
    			set.add(cur);

    		}
    		System.out.println(badness);
    	}
   	}
}
