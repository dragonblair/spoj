import java.util.Scanner;

 class Main {

	public static void main(String[] args){
		int n;
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		int q;
		int[] ans = new int[158];
		int[] array = new int[n];
		for(int i = 0; i < n; i++)
			array[i] = sc.nextInt();
		for(int i = 0; i < n ; i++){
			ans = new int[158];
			q = array[i];
			int k = 0;
			ans[0] = 1;
			int carry = 0;
			for(int j = 2; j <= q; j++ ){
				
				for(int rupa = 0; rupa <= k; rupa++){
					//System.out.println("Multiplying " + ans[rupa] + "with " + j + "k:" + k);
					ans[rupa] *= j;
					ans[rupa] += carry;
					if(ans[rupa] > 9){
						//System.out.print("Answer: " + ans[rupa] + "ekkuva vundi anduke :");
						carry = ans[rupa] / 10;
						ans[rupa] = ans[rupa] % 10;
						//System.out.println("carry: " + carry + "ans[rupa]:"  + ans[rupa] + "rupa:" + rupa );
						
						
					}
					else
						carry = 0;
				}
				
				while(carry != 0){
					++k;
					   //System.out.println("In here with carry " + carry);
					   ans[k] = carry % 10;
					   carry /= 10;
				}
				
			}
			   
			
				
			for(int l = k; l >= 0; l--)
				System.out.print(ans[l]);	
					System.out.println();	
			}
			
		
		
	}
}
		
	


