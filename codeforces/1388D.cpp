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
#include<cstring>
#include<chrono>
#include<random>
#include<bitset>
#include<stack>
#include<unordered_map>

using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define eb              emplace_back
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
template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(const char *t) {cerr << '\"' << t << '\"';}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned long long t) {cerr << t;}
void _print(bool t) {cerr << (t ? "true" : "false");}
void _print(float t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

#ifndef ONLINE_JUDGE
#define debug(x) cerr << "["<< #x << "] = "; _print(x); cerr << endl;
#else
#define debug(x)
#endif


int dfs_for_topo(int cur, vi &vis, vi &ans, vi *adj)
{
	vis[cur] = 1;

	for (int nb : adj[cur])
		if (!vis[nb])
		{
			int cf = dfs_for_topo(nb, vis, ans, adj);

			if (!cf)
				return 0;
		}
		else if (vis[nb] == 1)
			return 0;

	vis[cur] = 2;

	ans.pb(cur);
	return 1;
}
vi order;
int topo_sort(int *arr, int *brr, int n)
{
	vi vis(n + 1, 0);
	mk(adj, n + 1, vi);
	vi ans;

	for (int i = 1; i <= n; ++i)
		if (brr[i] != -1)
			adj[i].pb(brr[i]);

	for (int i = 1; i <= n; ++i)
		if (!vis[i])
			dfs_for_topo(i, vis, ans, adj);

	reverse(ans.begin(), ans.end());

	//cout << ans.size() << '\n';

	int final = 0;

	vi to_do;

	for (int id : ans)
	{

		if (arr[id] < 0)
		{
			to_do.pb(id);
			continue;
		}

		order.pb(id);

		final += arr[id];

		if (brr[id] != -1)
			arr[brr[id]] += arr[id];
	}

	reverse(to_do.begin(), to_do.end());

	for (int id : to_do)
	{
		order.pb(id);
		final += arr[id];

		if (brr[id] != -1)
			arr[brr[id]] += arr[id];
	}

	return final;
}

int32_t main()
{
	FIO;
	int n; cin >> n;
	mk(arr, n + 1, int);
	mk(brr, n + 1, int);

	for (int i = 1; i <= n; ++i)
		cin >> arr[i];

	for (int i = 1; i <= n; ++i)
		cin >> brr[i];

	cout << topo_sort(arr, brr, n) << '\n';

	for (int i : order)
		cout << i << ' ';

	cout << '\n';
	return 0;
}
