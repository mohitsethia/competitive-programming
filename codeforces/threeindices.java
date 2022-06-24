import java.util.Scanner;
public class threeindices{
	public static void main(String[] args){
		Scanner scn = new Scanner(System.in);
		int t = scn.nextInt();
		while(t > 0){
			t--;
			int n = scn.nextInt();
			int[] a = new int[n];
			for(int i = 0; i < n; i++){
				a[i] = scn.nextInt();
			}
			boolean flag = true;
			for(int i = 1; i < n-1; i++){
				if(a[i] > a[i-1] && a[i] > a[i+1]){
					System.out.println("YES");
					System.out.println((i) + " " + (i+1) + " " + (i+2));
					flag = false;
					break;
				}
			}
			if(flag){
				System.out.println("NO");
			}
		}
	}
}