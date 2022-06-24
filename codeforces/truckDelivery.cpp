#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<numeric>
using namespace std;
#define int long long
const int N = 2e5 + 1;

vector<vector<int> > graph[N];
pair<int, int>  queries[N];
int ans[N];
vector<pair<int, int> > node_queries[N];
struct segmentTree{
    int n;
    vector<int> st;
    int merge(int a, int b){
        return gcd(a, b);
    }
    void build(int start, int end, int node){
        if(start == end){
            st[node] = 0;
            return ;
        }
        int mid = (end+start)/2;
        build(start, mid, 2*node+1);
        build(mid+1, end, 2*node+2);
        st[node] = merge(st[2*node+1], st[2*node+2]);
        return;
    }

    int queryUtil(int start, int end, int l, int r, int node){
        if(start > r || end < l || l > r){
            return 0;
        }
        if(start >= l && end <= r){
            return st[node];
        }
        int mid = (start+end)/2;
        int left = queryUtil(start, mid, l, r, 2*node+1);
        int right = queryUtil(mid+1, end, l, r, 2*node+2);
        return merge(left, right);
    }   
    int query(int l, int r){
        return queryUtil(0, n-1, l, r, 0);
    }

    void updateUtil(int start, int end, int idx, int val, int node){
        if(start == end){
            st[node] = val;
            return;
        }
        int mid = (start+end)/2;
        if(idx >= start && idx <= mid){
            updateUtil(start, mid, idx, val, 2*node+1);
        }
        else{
            updateUtil(mid+1, end, idx, val, 2*node+2);
        }
        st[node] = merge(st[2*node+1], st[2*node+2]);
        return;
    }
    void update(int idx, int val){
        updateUtil(0, n-1, idx, val, 0);
        return;
    }
}tree;

void dfs(int curr, int par){
    for(auto x: graph[curr]){
        int to = x[0];
        int l = x[1];
        int a = x[2];
        if(to != par){
            tree.update(l, a);
            for(auto y: node_queries[to]){
                ans[y.second] = tree.query(0, y.first);
            }
            dfs(to, curr);
            tree.update(l, 0);
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    tree.n = n;
    tree.st.resize(4*n+5);
    for(int i = 0; i < n-1; i++){
        int x, y, l, a;
        cin >> x >> y >> l >> a;
        graph[x].push_back({y, l, a});
        graph[y].push_back({x, l, a});
    }
    for(int i = 0; i < m; i++){
        cin >> queries[i].first >> queries[i].second;
        node_queries[queries[i].first].push_back(make_pair(queries[i].second, i));
    }
    dfs(1, 0);
    for(int i = 0; i < m; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < N; i++){
        node_queries[i].clear();
        graph[i].clear();
        ans[i] = 0;
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}























/*
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<iomanip>
#include<numeric>
#include<climits>
#include<cmath>
#include<chrono>
#include<random>

using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());


// While doing a query, only that nodes
// will be non-zero, which are part of my path

struct info
{
	int x;
	info () : x(0) {};
};

struct SegTree
{
	int N;
	vector<info> st;

	SegTree(int n)
	{
		N = n;
		st.resize(4 * N + 5);
	}

	void merge(info &cur, info &l, info &r)
	{
		cur.x = gcd(l.x, r.x);
	}

	void Build(int node, int L, int R)
	{
		if (L == R)
		{
			st[node].x = 0;
			return;
		}
		int M = (L + R) / 2;
		Build(node * 2, L, M);
		Build(node * 2 + 1, M + 1, R);
		merge(st[node], st[node * 2], st[node * 2 + 1]);
	}

	info Query(int node, int L, int R, int i, int j)
	{
		if (j < L || i > R)
			return info();
		if (i <= L && R <= j)
			return st[node];
		int M = (L + R) / 2;
		info left = Query(node * 2, L, M, i, j);
		info right = Query(node * 2 + 1, M + 1, R, i, j);
		info cur;
		merge(cur, left, right);
		return cur;
	}

	void Update(int node, int L, int R, int pos, int val)
	{
		if (L == R)
		{
			st[node].x = val;
			return;
		}
		int M = (L + R) / 2;
		if (pos <= M)
			Update(node * 2, L, M, pos, val);
		else
			Update(node * 2 + 1, M + 1, R, pos, val);

		merge(st[node], st[node * 2], st[node * 2 + 1]);
	}

	info query(int l, int r) { return Query(1, 0, N - 1, l, r); }

	void update(int pos, int val) { Update(1, 0, N - 1, pos, val); }

	void build() { Build(1, 0, N - 1); }
};

void dfs(int n, SegTree &st, vi &ans, vector<vector<vi>> &adj, vector<vector<vi> > &queries, vector<vi> &edges, int i = 1, int j = 0)
{
	for (auto q : queries[i])
	{
		int W = q[0], id = q[1];
		vi temp = {W + 1, -1, -1, -1};
		auto it = lower_bound(edges.begin(), edges.end(), temp);

		if (it == edges.begin())
			ans[id] = 0;

		else
		{
			it--;
			int end_id = it - edges.begin();
			ans[id] = st.query(0, end_id).x;
		}
	}

	for (auto &e : adj[i])
	{
		int nb = e[0];

		if (nb == j)
			continue;

		int id = e[1];
		st.update(id, edges[id][1]);
		dfs(n, st, ans, adj, queries, edges, nb, i);
		st.update(id, 0);
	}
}

int32_t main()
{
	FIO;
	int tc; cin >> tc;
	for (int tnum = 1; tnum <= tc; ++tnum)
	{
		int n, q; cin >> n >> q;
		vector<vector<vi> > adj(n + 1);
		vector<vi> edges(n - 1);

		for (int w = 0; w < n - 1; ++w)
		{
			int i, j, l, c; cin >> i >> j >> l >> c;
			edges[w] = {l, c, i, j};
		}

		sort(edges.begin(), edges.end());

		for (int w = 0; w < n - 1; ++w)
		{
			int i = edges[w][2], j = edges[w][3];
			adj[i].pb({j, w});
			adj[j].pb({i, w});
		}

		vector<vector<vi> > queries(n + 1);

		for (int i = 0; i < q; ++i)
		{
			int c, w; cin >> c >> w;
			queries[c].pb({w, i});
		}

		SegTree st(n - 1);
		vi ans(q);

		dfs(n, st, ans, adj, queries, edges);

		cout << "Case #" << tnum << ": ";

		for (int i = 0; i < q; ++i)
			cout << ans[i] << ' ';
		cout << '\n';
	}
	return 0;
}
*/
