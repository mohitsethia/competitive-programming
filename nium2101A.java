import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class nium2101A
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
        FastScanner input = new FastScanner();
        StringBuilder result = new StringBuilder();
        int tc = input.nextInt();
        while (tc-- > 0) {
            int n = input.nextInt();
            HashSet<String> set = new HashSet<String>();
            for (int i = 0; i < n; i++) {
                String s = input.next();
                set.add(s);
            }
            if(set.size() > 12){
                System.out.println("no");
            }
            else if(n < 12){
                System.out.println("no");
            }
            else{
                System.out.println("yes");
            }
        }
    }
    static class FastScanner
    {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        String next()
        {
            while (!st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                }
            }
            return st.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {

            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine() throws IOException
        {
            return br.readLine();
        }
    }

}
