import java.util.*;
class Main {
public static void main(String[] args){
	String s = new String();
	Scanner sc = new Scanner(System.in);
	int n;
	while(true){
		n = sc.nextInt();
		if(n == 0)
			break;
		else{
			s = sc.next();
			StringBuilder ss = new StringBuilder(s);
			StringBuilder[] splits = new StringBuilder[s.length()/n];
			int k = 0;
			for(int i = 0; i < splits.length; i++ ){
				splits[i] = new StringBuilder(ss.substring(k, k+n));
				if(i % 2 != 0){
					splits[i] = splits[i].reverse();
				}
					
				//System.out.println(splits[i]);
				k += n;		
			}
			for(int i = 0; i < n ; i++){
				for(int j = 0; j < splits.length ; j++)
					System.out.print(splits[j].charAt(i));
				
			}
			System.out.println();
		}
	}
	
	
}
}
