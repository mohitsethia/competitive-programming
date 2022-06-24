import java.util.*;
import java.lang.*;
import java.io.*;
import java.util.Scanner;
import java.util.Arrays;
import java.math.BigInteger;
class friendspairing{
	public static final long MOD = 1000000007;
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0){
			long n = sc.nextLong();
			long[] dp = new long[(int)n+1];
			for(int i = 0; i <= n; i++){
				if(i <= 2){
					dp[i] = Long.valueOf(i);
				}
				else{
					dp[i] = dp[i-1] + ((i)-1L)*dp[i-2];
				}
			}
			System.out.println(dp[(int)n] % MOD);
		}
	}
}