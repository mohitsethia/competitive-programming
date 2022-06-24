import java.util.Scanner;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
class ScanningData
{
	public static void main(String args[]) throws IOException
	{
	// Using Scanner for Getting Input from User
		System.out.print("Reading through scanner: ");
		Scanner sc = new Scanner(System.in);
		String s = sc.nextLine();
		System.out.println("Input from Scanner is : "+s);
		//Enter data using BufferReader
		System.out.print("Using BufferedReader: ");
		BufferedReader reader =
		new BufferedReader(new InputStreamReader(System.in));
		// Reading data using readLine
		String name1 = reader.readLine();
		// Printing the read line
		System.out.println("Input form BufferedReader is: "+name1);
		// Using Console to input data from user
		System.out.print("Using System console: ");
		String name2 = System.console().readLine();
		System.out.println("Input from System Console: "+name2);
	}
}