import java.io.*;
import java.util.Scanner;
import java.util.Arrays;
import java.lang.*;
import java.util.*;
class matrixchain{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		for(int i = 0; i < n; i++){
			a[i] = sc.nextInt();
		}
		System.out.println(chainmultiplication(a, n));
	}
	public static int chainmultiplication(int[] m, int n) {
		int[][] mat = new int[n][n];
		int i, j, k, l;
		for(i = 1; i < n; i++){
			mat[i][i] = 0;
		}
		for(l = 2; l < n; l++){
			for(i = 1; i <= n-l; i++){
				j = i+l-1;
				if(j == n){
					continue;
				}
				mat[i][j] = Integer.MAX_VALUE;
				for(k = i; k < j; k++){
					mat[i][j] = Math.min(mat[i][j], mat[i][k] + mat[k+1][j] + m[i-1]*m[k]*m[j]);
				}
			}
		}
/*		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				System.out.print(mat[i][j] + " ");
			}
			System.out.println();
		}
		for(i = 0; i < n; i++){
			System.out.print(m[i]);
		}
*/
		return mat[1][n-1];
	}
}
