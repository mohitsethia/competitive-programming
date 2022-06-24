//print all subsets with given sum
import java.util.*;
import java.util.Scanner;
import java.io.*;
import java.lang.*;
import java.util.Arrays;
/*
//Recursive approach
class allsubsetsum{
	public int cnt = 0;
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-->0){
			int n = sc.nextInt();
//			Vector<Integer> v = new Vector<Integer> ();
	`		int[] a = new int[n];
			for(int i = 0; i < n; i++){
				a[i] = sc.nextInt();
			}
			int sum = sc.nextInt();
			printsubsets(a, n, v, sum);
			System.out.println(cnt);
			cnt = 0;
		}
	}
	public static void printsubsets(int[] a, int n, int sum, int cnt){
		if(sum == 0){
			cnt++;
			return;
		}
		if(n == 0){
			return;
		}
		printsubsets(a, n-1, v, sum, cnt);
//		Vector<Integer> v1 = new Vector<Integer> (v);
//		v1.add(a[n-1]);
		printsubsets(a, n-1, v1, sum-a[n-1], cnt);
	}
}
*/
class allsubsetsum{
	public static final int MOD = 1000000007;
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-->0){
			int n = sc.nextInt();
			int[] a = new int[n];
			for(int i = 0; i < n; i++){
				a[i] = sc.nextInt();
			}
			int sum = sc.nextInt();
			int ans =  countsubsets(a, sum);
		}
	}	
	public static int countsubsets(int[] a, int sum){
		int[][] T = new int[a.length+1][sum+1];
		for(int i = 0; i <= a.length; i++){
			T[i][0] = 1;
		}
		for(int i = 1; i <= sum; i++){
			T[0][i] = 0;
		}
		for(int i = 1; i <= a.length; i++){
			for(int j = 1; j <= sum; j++){
				if(a[i-1] <= j){
					T[i][j] = T[i-1][j]%MOD + T[i-1][j-a[i]]%MOD;
				}
				else{
					T[i][j] = T[i-1][j]%MOD;
				}
			}
		}
		return T[a.length][sum]%MOD;
	}
}
