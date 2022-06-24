import java.util.*;
import java.util.Scanner;
import java.io.*;
import java.lang.*;
import java.util.Arrays;
class checksubsequence{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-->0){
			String s1 = sc.next();
			String s2 = sc.next();
			int i = 0, j = 0;
			while(i < s1.length() && j < s2.length()){
				if(s1.charAt(i) == s2.charAt(j)){
					i++;
					j++;
				}
				else{
					i++;
				}
			}
			if(j == s2.length()){
				System.out.println("1");
			}
			else{
				System.out.println("0");
			}
		}
	}
}