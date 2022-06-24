import java.util.Scanner;
public class string{
	public static void main(String[] args){
		//To take the string input from the user
		Scanner scn = new Scanner(System.in);
		String astring = scn.nextLine();
		System.out.println(astring);
		String str = "Hello";
		System.out.println(str);
		System.out.println(str.charAt(2));
		System.out.println(str.substring(2, 4));
		System.out.println(str.length());
		String str2 = "Bye";
		String s = str + str2;
		String s4 = str.concat(str2);
		System.out.println(s);
		System.out.println(s4);
		System.out.println(str2);
		System.out.println(str.indexOf("el")); //gives the starting index 
		//where the substring is present,
		//else if the string is not present it gives -1 as the output
		//startsWith to check if the string starts with that string.
		System.out.println(str.startsWith("he"));
		System.out.println(str.startsWith("He"));
		//startsWith return the boolean value true or false
		//if string starts with the given string it gives true.
		//Else false

	}
}