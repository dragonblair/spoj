import java.util.*;
class Solution{
	public static void main(String[] args){
		int n;
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		for(int k = 0; k < n; k++){
			int size = sc.nextInt();
			ArrayList<Integer> list1 = new ArrayList<Integer>();
			ArrayList<Integer> list2 = new ArrayList<Integer>();
			for(int i = 0; i < size; i++)
				list1.add(sc.nextInt());
			for(int i = 0; i < size; i++)
				list2.add(sc.nextInt());
			long sum = 0;
			Collections.sort(list1);
			Collections.sort(list2);
			for(int i = 0; i < size; i++)
				sum += list1.get(i) * list2.get(i);
			System.out.println(sum);
		}

	}
}