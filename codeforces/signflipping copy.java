import java.util.Scanner;
public class signflipping{
	public static void main(String[] args){
		Scanner scn = new Scanner(System.in);
		int t = scn.nextInt();
		while(t > 0){
			int n = scn.nextInt();
			int[] a = new int[n];
			for(int i = 0; i < n; i++){
				a[i] = scn.nextInt();
				if(a[i] < 0){
					a[i] = -a[i];
				}
			}
			for(int i = 1; i < n; i += 2){
				a[i] = -a[i];
			}
			for(int i = 0; i < n; i++){
				System.out.print(a[i] + " ");
			}
			System.out.println();
			t--;
//		System.out.println(n);
		}
	}
}