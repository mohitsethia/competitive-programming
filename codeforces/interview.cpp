#include <iostream>
#include <algorithm>

using namespace std;

vector<string> solve(vector<string> &a, int d, int q, vector<int> &k, vector<int> &m) {
    vector<vector<string>> ans(d+1);
    for(int i = 0; i < a.size(); i++) {
        for(int j = 1; j <= d; j++) {
            string str = a[i].substr(a[i].size()-j);
            ans[j].push_back(str);
        }
    }
    for(int i = 1; i <= d; i++) {
        sort(ans[i].begin(), ans[i].end());
    }
    vector<string> res;
    for(int i = 0; i < q; i++) {
        res.push_back(ans[m[i]][k[i]-1]);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int d;
    cin >> d;
    int q;
    cin >> q;
    vector<int> k(q), m(q);
    for(int i = 0; i < q; i++) cin >> k[i];
    for(int j = 0; j < q; j++) cin >> m[j];
    vector<string> ans = solve(a, d, q, k, m);
    for(auto it: ans) {
        cout << it << "\n";
    }
    return 0;
}
