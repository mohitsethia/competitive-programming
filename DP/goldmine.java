import java.util.*;
import java.lang.*;
import java.io.*;
import java.util.Scanner;
import java.util.Arrays;
class goldmine{
	public static void main(String arg[]){
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0){
			int n = sc.nextInt();
			int m = sc.nextInt();
			int arr[][] = new int[n][m];
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					arr[i][j] = sc.nextInt();
				}
			}
			int gold[][] = new int[n][m];
			for(int[] row : gold){
				Arrays.fill(row, 0);
			}
			for(int col = m-1; col >= 0; col--){
				for(int row = 0; row < n; row++){
					int right = (col == m-1) ? 0 : gold[row][col+1];
					int right_up = (row == 0 || col == m-1) ? 0 : gold[row-1][col+1];
					int right_down = (row == n-1 || col == m-1) ? 0 : gold[row+1][col+1];
					gold[row][col] = arr[row][col] + Math.max(right, Math.max(right_up, right_down));
				}
			}
			int res = gold[0][0];
			for(int i = 1; i < n; i++){
				res = Math.max(res, gold[i][0]);
			}
			System.out.println(res);
		}
	}
}