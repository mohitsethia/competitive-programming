import java.util.*;
import java.lang.*;
import java.io.*;
import java.util.Scanner;
import java.util.Arrays;
class coinchange{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0){
			int n = sc.nextInt();
			int[] a = new int[n];
			for(int i = 0; i < n; i++){
				a[i] = sc.nextInt();
			}
			int s = sc.nextInt();
			int[] table = new int[s+1];
			Arrays.fill(table, 0);
			table[0] = 1;
			for(int i = 0; i < n; i++){
				for(int j = a[i]; j <= s; j++){
					table[j] += table[j-a[i]];
				}
			}
			System.out.println(table[s]);
		}
	}
}