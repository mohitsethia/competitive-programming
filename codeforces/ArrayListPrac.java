//Array List
import java.util.Scanner;
import java.util.ArrayList;
public class ArrayListPrac{
	public static void main(String[] args){
		ArrayList<Integer> list = new ArrayList<>();
		System.out.println(list);
		System.out.println(list.size());
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		for(int i = 0; i < n; i++){
			int x = scn.nextInt();
			list.add(x);
		}
		System.out.println(list);
		System.out.println(list.size());
		System.out.println(list.get(2));
		list.remove(2);
		System.out.println(list);
	}	
}