import java.util.Scanner;
public class omkarandcompletion{
	public static void main(String[] args){
		Scanner scn = new Scanner(System.in);
		int t = scn.nextInt();
		while(t > 0){
			t--;
			int n = scn.nextInt();
			for(int i = 0; i < n; i++){
				System.out.print("1 ");
			}
			System.out.println();
		}
	}
}