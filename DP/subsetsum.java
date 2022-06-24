import java.util.*;
import java.io.*;
import java.lang.*;
import java.util.Scanner;
import java.util.Arrays;
class subsetsum{
	//using scanner
	/*
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0){
			int n = sc.nextInt();
			int[] a = new int[n];
			for(int i = 0; i < n; i++){
				a[i] = sc.nextInt();
			}
			boolean part = partition(a);
			if(part){
				System.out.println("YES");
			}
			else{
				System.out.println("NO");
			}
		}
	}
	*/
	//using buffer reader
	public static void main(String args[])throws IOException{ 
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(in.readLine());
		while(t-- > 0){
			System.out.println(t);
			int N = Integer.parseInt(in.readLine());

			System.out.println(N);
			String input_line[] = in.readLine().trim().split("\\s+");

			System.out.println(Arrays.toString(input_line));
			for(int i = 0; i < input_line.length; i++){
				System.out.println(i + " = " + input_line[i]);
			}
			int arr[] = new int[N];
			for(int i = 0; i < N; i++){
				arr[i] = Integer.parseInt(input_line[i]);
			}
			Solution ob = new Solution();
			int x = ob.partition(arr);
			if(x == 1){
				System.out.println("YES");
			}
			else{
				System.out.println("NO");
			}
		}
	}
}
class Solution{
	/*
	public boolean subset(int[] a, int target){
		boolean[][] T = new boolean[a.length+1][target+1];
		for(int i = 0; i <= a.length; i++){
			T[i][0] = true;
		}
		for(int i = 1; i <= a.length; i++){
			for(int j = 1; j <= target; j++){
				if(j - a[i-1] >= 0){
					T[i][j] = T[i-1][j-a[i-1]] || T[i-1][j];
				}
				else{
					T[i][j] = T[i-1][j];
				}
			}
		}
		return T[a.length][target];
	}
	*/
	public static int partition(int[] a){
		int sum = 0;
		for(int i = 0; i < a.length; i++){
			sum += a[i];
		}
		if(sum%2 != 0){
			return 0;
		}
		sum /= 2;
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
			}
		}
		if(T[a.length][sum]){
			return 1;
		}
		else{
			return 0;
		}
	}
}