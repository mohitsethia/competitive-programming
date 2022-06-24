import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class nium2101C
{
    static Vector<Integer> merge(Vector<Integer> v1,
                               Vector<Integer> v2)
    {
        int i = 0, j = 0;

        // Final vector to return
        // after merging
        Vector<Integer> v = new Vector<>();

        // Loop continues until it reaches
        // the end of one of the vectors
        while (i < v1.size() && j < v2.size())
        {
            if (v1.elementAt(i) <= v2.elementAt(j))
            {
                v.add(v1.elementAt(i));
                i++;
            }
            else
            {
                v.add(v2.elementAt(j));
                j++;
            }
        }

        // Here, simply add the remaining
        // elements to the vector v
        for (int k = i; k < v1.size(); k++)
            v.add(v1.elementAt(k));
        for (int k = j; k < v2.size(); k++)
            v.add(v2.elementAt(k));
        return v;
    }

    // Procedure to build the segment tree
    static void buildTree(Vector<Integer>[] tree, int[] arr,
                        int index, int s, int e)
    {

        // Reached the leaf node
        // of the segment tree
        if (s == e)
        {
            tree[index].add(arr[s]);
            return;
        }

        // Recursively call the buildTree
        // on both the nodes of the tree
        int mid = (s + e) / 2;
        buildTree(tree, arr, 2 * index, s, mid);
        buildTree(tree, arr, 2 * index + 1, mid + 1, e);

        // Storing the final vector after merging
        // the two of its sorted child vector
        tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
    }

    // Query procedure to get the answer
    // for each query l and r are query range
    static int query(Vector<Integer>[] tree, int index, int s,
                    int e, int l, int r, int k)
    {

        // out of bound or no overlap
        if (r < s || l > e)
            return 0;

        // Complete overlap
        // Query range completely lies in
        // the segment tree node range
        if (s >= l && e <= r)
        {

            // binary search to find index of k
            return (tree[index].size() - lowerBound(tree[index],
                    tree[index].size(), k));
        }

        // Partially overlap
        // Query range partially lies in
        // the segment tree node range
        int mid = (s + e) / 2;
        return (query(tree, 2 * index, s, mid, l, r, k) +
                query(tree, 2 * index + 1, mid + 1, e, l, r, k));
    }

    // Function to perform the queries
    static void performQueries(int L[], int R[], int K[],
                        int n, int q, Vector<Integer> tree[])
    {
        for (int i = 0; i < q; i++)
        {
            System.out.println(query(tree, 1, 0, n - 1,
                                    L[i] - 1, R[i] - 1, K[i]));
        }
    }

    static int lowerBound(Vector<Integer> array,
                        int length, int value)
    {
        int low = 0;
        int high = length;
        while (low < high)
        {
            final int mid = (low + high) / 2;
            if (value <= array.elementAt(mid))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
        FastScanner sc = new FastScanner();
        int n = sc.nextInt();
        int q = sc.nextInt();
        int a[] = new int[n];
        @SuppressWarnings("unchecked")
        Vector<Integer>[] tree = new Vector[4 * n + 1];
        for(int i = 0; i < n; i++){
            int x = sc.nextInt();
            a[i] = x;
            tree[i] = new Vector<>();
        }
        for(int i = n; i < (4*n + 1); i++){
            tree[i] = new Vector<>();
        }
        buildTree(tree, a, 1, 0, n-1);
        int[] L = new int[q];
        int[] R = new int[q];
        int[] K = new int[q];
        for(int i = 0; i < q; i++){
            L[i] = sc.nextInt();
            R[i] = sc.nextInt();
            K[i] = sc.nextInt();
        }
        performQueries(L, R, K, n, q, tree);
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
