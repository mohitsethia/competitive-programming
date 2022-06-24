import java.io.*;
import java.util.*;
import java.util.Scanner;
import java.util.Arrays;
import java.lang.*;
class lcs{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-->0){
			 int n = sc.nextInt();
			 int m = sc.nextInt();
			 String s1 = sc.next();
			 String s2 = sc.next();
			 int[][] dp = new int[n+1][m+1];
			 for(int i = 0; i <= n; i++){
			 	dp[i][0] = 0;
			 }
			 for(int j = 0; j <= m; j++){
			 	dp[0][j] = 0;
			 }
			 for(int i = 1; i <= n; i++){
			 	for(int j = 1; j <= m; j++){
			 		if(s1.charAt(i-1) == s2.charAt(j-1)){
			 			dp[i][j] = 1 + dp[i-1][j-1];
			 		}
			 		else{
			 			dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
			 		}
			 	}
			 }
			 System.out.println(dp[n][m]);
		}
	}
}