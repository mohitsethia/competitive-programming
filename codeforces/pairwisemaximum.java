import java.util.Scanner;
public class pairwisemaximum{
	public static void main(String args[]){
		Scanner scn = new Scanner(System.in);
		int t = scn.nextInt();
		while(t > 0){
			t--;
			int x = scn.nextInt();
			int y = scn.nextInt();
			int z = scn.nextInt();
			int mx = Math.max(x, Math.max(y, z));
			int count = 0, mx1 = 0;
			if(mx == x){
				count++;
			}
			if(mx == y){
				count++;
			}
			if(mx == z){
				count++;
			}
			if(count == 1){
				System.out.println("NO");
			}
			else if(count == 2){
				if((mx == x && mx == y)){
					mx1 = z;
				}
				if(mx == y && mx == z){
					mx1 = x;
				}
				if(mx == x && mx == z){
					mx1 = y;
				}
				System.out.println("YES");
				System.out.println(mx + " " + mx1 + " 1");
			}
			else{
				System.out.println("YES");
				System.out.println(mx + " " + mx + " " +mx);
			}
		}
	}
}