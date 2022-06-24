//subset with sum divisible by m
import java.util.*;
import java.io.*;
import java.lang.*;
import java.util.Scanner;
import java.util.Arrays;
class sumdivisble{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0){
			int n = sc.nextInt();
			int m = sc.nextInt();
			int[] a = new int[n];
			for(int i = 0; i < n; i++){
				a[i] = sc.nextInt();
			}
			if(n > m){
				System.out.println("1");
			}
			else{
				if(check(a, m)){
					System.out.println("1");
				}
				else{
					System.out.println("0");
				}
			}
		}
	}
	public static boolean check(int[] a, int m){
		int sum = 0;
		for(int i = 0; i < a.length; i++){
			sum += a[i];
		}
		boolean[][] T = new boolean[a.length+1][sum+1];
		for(int i = 0; i <= a.length; i++){
			T[i][0] = true;
		}
		for(int i = 1; i <= a.length; i++){
			for(int j = 1; j <= sum; j++){
				if(j - a[i-1] >= 0){
					T[i][j] = T[i-1][j] || T[i-1][j-a[i-1]];
				}
				else{
					T[i][j] = T[i-1][j];
				}
				if(j%m == 0 && T[i][j]){
					return true;
				}
			}
		}
		int j = 1;
		for(int i = m; i <= sum; i = m * j){
			if(T[a.length][i]){
				return true;
			}
			j++;
		}
		return false;
	}
}
