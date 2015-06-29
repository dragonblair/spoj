import java.util.ArrayList;
import java.util.Scanner;
 
class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
	ArrayList<Integer> list = new ArrayList<Integer>();
	Scanner sc = new Scanner(System.in);
	int f = 100;
	while(f == 100){
			int r = sc.nextInt();
			if(r == 42){
				f = 0;
				continue;
			}
				
			list.add(r);
	}
	for(int i = 0; i < list.size(); i++){
		System.out.println(list.get(i));
	}
	}
}