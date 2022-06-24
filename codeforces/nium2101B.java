import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class nium2101B
{
    static void removeDuplicate(char str[], int n)
    {
       // Create a set using String characters
    // excluding '\0'
        HashSet<Character> s = new LinkedHashSet<>(n - 1);
      // HashSet doesn't allow repetition of elements
        for (char x : str)
            s.add(x);

        // Print content of the set
        
        for (char x : s)
            System.out.print(x);
    }
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
        FastScanner input = new FastScanner();
        StringBuilder result = new StringBuilder();
            int n = input.nextInt();
            HashSet<String> set = new HashSet<String>();
            for (int i = 0; i < n; i++) {
                String a = input.next();
                String b = input.next();
                int[] pre = new int[26];
                for(int j = 0; j < a.length(); j++){
                    pre[a.charAt(j)-'a'] = 1;
                }
                String temp = new String();
                int[] p = new int[26];
                for(int j = 0; j < b.length(); j++){
                    if(pre[b.charAt(j)-'a'] == 0 && p[b.charAt(j)-'a'] == 0){
                        p[b.charAt(j)-'a'] = 1;
                        temp += b.charAt(j);
                    }
                }
                char str[] = temp.toCharArray();
                Arrays.sort(str);
                if(temp.length() > 0){
                    for(char x: str)
                        System.out.print(x);
                }
                else
                    System.out.print("-1");
                System.out.println();
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


