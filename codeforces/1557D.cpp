#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>

using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair

class SegTree {

public:
	vector<pii> st, lazy;
	int n, l1, r1;
	SegTree(int n, int l1, int r1)                       //st nodes are from l1 to r1, ie, n leaves, from [l1,r1]
	{
		int ht = ceil(log2(n));
		this->n = n;
		this->l1 = l1;
		this->r1 = r1;
		ht = (1ll << (ht + 1)) - 1;
		st = vector<pii>(ht, mp(0, 0));
		lazy = vector<pii>(ht, mp(0, 0));
	}
	void upd(int l, int r, int i, int l1, int r1, pii val)
	{
		if (lazy[i].first != 0ll && lazy[i].second != 0ll)
		{
			st[i] = max(st[i], lazy[i]);

			if (l != r)
			{
				lazy[i * 2 + 1]  = max(lazy[i], lazy[2 * i + 1]);
				lazy[i * 2 + 2]  = max(lazy[i], lazy[2 * i + 2]);
			}

			lazy[i] = mp(0, 0);
		}

		if (l > r || l > r1 || r < l1)
			return ;

		if (l >= l1 && r <= r1)
		{
			st[i] = max(st[i], val);

			if (l != r)
			{
				lazy[i * 2 + 1]  = max(val, st[2 * i + 1]);
				lazy[i * 2 + 2]  = max(val, st[2 * i + 2]);
			}
			return;
		}

		int mid = (l + r) / 2;
		upd(l, mid, 2 * i + 1, l1, r1, val);
		upd(mid + 1, r, 2 * i + 2, l1, r1, val);

		st[i] = max(st[2 * i + 1], st[2 * i + 2]);

	}

	pii quer(int l, int r, int i, int l1, int r1)
	{
		if (lazy[i].first != 0ll && lazy[i].second != 0ll)
		{
			st[i] = max(st[i], lazy[i]);

			if (l != r)
			{
				lazy[i * 2 + 1]  = max(lazy[i], lazy[2 * i + 1]);
				lazy[i * 2 + 2]  = max(lazy[i], lazy[2 * i + 2]);
			}

			lazy[i] = mp(0, 0);
		}

		if (l > r || l > r1 || r < l1)
			return mp(0, 0);

		if (l1 <= l && r1 >= r)
			return st[i];

		if (l == r)
			return st[i];

		int mid = (l + r) / 2;
		pii p1 = quer(l, mid, 2 * i + 1, l1, r1);
		pii p2 = quer(mid + 1, r, 2 * i + 2, l1, r1);

		return max(p1, p2);
	}

	void update(int l, int r, pii val)
	{
		upd(l1, r1, 0, l, r, val);
	}

	pii query(int l, int r)
	{
		return quer(l1, r1, 0, l, r);
	}
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    set<int> vals;
    vector<vector<pair<int, int> > > ranges(n+1);
    for(int i = 1; i <= m; i++){
        int row, l, r;
        cin >> row >> l >> r;
        vals.insert(l);
        vals.insert(r);
        ranges[row].push_back({l, r});
    }
    map<int, int> code;
    int cnt = 1;
    for(int i: vals){
        code[i] = cnt++;
    }
    cnt--;
    SegTree st(cnt, 1, cnt);
    vector<pair<int, int > > dp(n+1);
    for(int i = 1; i <= n; i++){
        for(pair<int, int > p: ranges[i]){
            dp[i] = max(dp[i], st.query(code[p.first], code[p.second]));
        }
        dp[i].first++;
        for(pair<int, int> p: ranges[i]){
            st.update(code[p.first], code[p.second], {dp[i].first, i});
        }
    }
    set<int> s;
    for(int i = 1; i <= n; i++){
        s.insert(i);
    }
    int mx = max_element(dp.begin(), dp.end()) - dp.begin();
    while(mx){
        s.erase(mx);
        mx = dp[mx].second;
    }
    cout << (int)s.size() << "\n";
    for(int i : s){
        cout << i << " ";
    }
    return 0;
}
