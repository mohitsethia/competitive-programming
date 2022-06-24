import java.util.*;
import java.lang.*;
import java.io.*;

public class fenwickTree{
	final static int MAX = 100000;	
    final static int INF = 100000;
	static int bit[];
    private static int n;
	public static void constructBITree(int arr[], int n){
        fenwickTree.n = n;
        bit = new int[n+1];
		for(int i=0; i<=n; i++)
			bit[i] = 0;
	}

    int getmin(int r) {
        int ret = -INF;
        for (; r >= 0; r = (r & (r + 1)) - 1){
            ret = Math.max(ret, bit[r]);
        }
        return ret;
    }
    void add(int idx, int val) {
        idx++;
        for (; idx < n; idx += (idx & (-idx))){
            bit[idx] += val;
        }
    }
    void update(int idx, int val) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] = Math.max(bit[idx], val);
    }
    void range_add(int l, int r, int val) {
        add(l, val);
        add(r + 1, -val);
    }
	public static void main(String args[]){
	    Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a[] = new int[n];
		for(int i = 0; i < n; i++){
		    a[i] = 0;
		}
		fenwickTree tree = new fenwickTree();
		tree.constructBITree(a, n);
		ArrayList<ArrayList<Integer> > updates = new ArrayList<ArrayList<Integer> >();
		int m = sc.nextInt();
		for(int i = 0; i < m; i++){
		    int l, r, val;
	        l = sc.nextInt();
	        r = sc.nextInt();
	        val = sc.nextInt();
	        l -= 1;
	        r -= 1;
	        tree.range_add(l, r, val);
	        ArrayList<Integer> Arr = new ArrayList<Integer>();
	        Arr.add(l);
	        Arr.add(r);
	        Arr.add(val);
	        updates.add(Arr);
		}
		int ans = Integer.MAX_VALUE;
		for(int i = 0; i < m; i++){
		    int l = updates.get(i).get(0);
		    int r = updates.get(i).get(1);
		    int val = updates.get(i).get(2);
		    tree.range_add(l, r, -val);
		    ans = Math.min(ans, tree.getmin(n-1));
		    tree.range_add(l, r, val);
		}
		System.out.println(ans);
	}
}
