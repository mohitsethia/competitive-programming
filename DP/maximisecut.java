//maximise the cut segment
import java.util.*;
import java.util.Scanner;
import java.io.*;
import java.lang.*;
import java.util.Arrays;
class maximisecut{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-->0){
			int n = sc.nextInt();
			int a = sc.nextInt();
			int b = sc.nextInt();
			int c = sc.nextInt();
			int[] dp = new int[n+1];
			Arrays.fill(dp, -1);
			int ans = solve(dp, n, a, b, c);
			System.out.println(ans);
		}
	}
	public static int solve(int[] dp, int n, int a, int b, int c){
		if(n == 0){
			return 0;
		}
		if(n < 0){
			return Integer.MIN_VALUE;
		}
		if(dp[n] != -1){
			return dp[n];
		}
		int ans = Integer.MIN_VALUE;
		ans = Math.max(solve(dp, n-a, a, b, c)+1, ans);
		ans = Math.max(solve(dp, n-b, a, b, c)+1, ans);
		ans = Math.max(solve(dp, n-c, a, b, c)+1, ans);
		return dp[n] = ans;	
	}
}