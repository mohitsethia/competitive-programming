import java.util.Scanner;
import java.math.RoundingMode; 
public class lastclassofmath{
	public static void main(String[] args){
		Scanner scn = new Scanner(System.in);
		int t = scn.nextInt();
		while(t > 0){
			t--;
			int n = scn.nextInt();
			if(n%2 == 0){
				System.out.println(n/2 + " " + n/2);
			}
			else{
				int ans = 0;
				for(int i = 3; i <= Math.sqrt(n); i += 2){
					if(n%i == 0){
						ans = max(ans, max(i, n/i));
					}
				}
				if(ans == 0){
					ans = 1;
				}
				System.out.println(ans + " " + (n-ans));
			}
		}
	}
	public static int max(int x, int y){
		if(x > y){
			return x;
		}
		else{
			return y;
		}
	}
	public static boolean isPrime(int num) {
		   if (num <= 1) {
		       return false;
		   }
		   for (int i = 2; i <= Math.sqrt(num); i++) {
		       if (num % i == 0) {
		           return false;
		       }
		   }
		   return true;
	}
	public static int gcd(int a, int b){
		if(b == 0){
			return a;
		}
		int c = a%b;
		return gcd(b, c);
	}
}