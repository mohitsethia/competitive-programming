//taking input from user
import java.util.Scanner;
public class loopjava{
	public static void main(String[] args){
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		 int sp=2, st=1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=sp; j++) {
            System.out.print(" ");
        }
        int val=i;
        if(i> n/2) {
            val=n+1-i;
        }
        for(int j=1; j<=st; j++) {
            System.out.print(val);
            if(j<=st/2)
                val++;
            else
                val--;

        }
        System.out.println();
        if(i<(n/2 +1)) {
            st+=2;
            sp--;
        }else {
            st-=2;
            sp++;
        }
    }
		/*
		int nsp = 2, nst = 1;
		for(int i=1; i<=n; i++) {
        for(int j=1; j<=nsp; j++) {
            System.out.print(" ");
        }
        for(int j=1; j<=nst; j++) {
            System.out.print("*");
        }
        System.out.println();
        if(i<(n/2+1)) {
            nsp--;
            nst=nst+2;
        }else {
            nsp++;
            nst=nst-2;
        }
    }
    */
//		for(int i = 0; i < n; i++){
//			System.out.print(n);
//		}
        /*
		int[][] arr = dec();
		for(int i = 0; i < arr.length; i++){
			for(int j = 0; j < arr[i].length; j++){
				System.out.print(arr[i][j] + " ");
			}
			System.out.println();
		}

		display(arr);
		*/
	}
	//returning a 2D array from a function
	/*
	private static int[][] dec(){
		Scanner scn = new Scanner(System.in);
		int row = scn.nextInt();
		int col = scn.nextInt();
		int[][] arr = new int[row][col];
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				arr[i][j] = scn.nextInt();
			}
		}
		return arr;
	}
	private static void display(int[][] arr){

		for(int i = 0; i < arr.length; i++){
			for(int j = 0; j < arr[i].length; j++){
				System.out.print(arr[i][j] + " ");
			}
			System.out.println();
		}
		/*
		for(int i = 0; i < arr.length; i++){
			for(int j = 0; j < arr[i].length; j++){
				System.out.print(arr[i][j] + " ");
			}
			System.out.println();
		}
	}
}
*/
}