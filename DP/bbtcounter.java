/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.util.Arrays;
import java.util.Scanner;
class bbtcounter {
    static final int MOD = 1000000007;
	public static void main (String[] args) {
		//code
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		long[] dp = new long[1001];
		dp[0] = 1;
		dp[1] = 1;
		for(int i = 2; i < 1001; i++){
		    dp[i] = (dp[i-1] * ((2 *(dp[i-1] + (dp[i-2])%MOD)))%MOD)%MOD;
		}
		while(t-->0){
		    int n = sc.nextInt();
		    System.out.println(dp[n]);
		}
	}
}