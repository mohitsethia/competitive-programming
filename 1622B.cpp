#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        vector<pair<int, int>> zeroes, ones;
        for(int i = 0; i < n; i++) {
            cin >> p[i];
        }
        string s;
        cin >> s;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') {
                zeroes.push_back({p[i], i});
            }
            else {
                ones.push_back({p[i], i});
            }
        }
        sort(zeroes.begin(), zeroes.end());
        sort(ones.begin(), ones.end());
        vector<int> ans(n);
        int cnt = 1;
        for(int i = 0; i < zeroes.size(); i++) {
            ans[zeroes[i].second] = cnt++;
        }
        for(int i = 0; i < ones.size(); i++) {
            ans[ones[i].second] = cnt++;
        }
        for(auto it: ans) {
            cout << it << " ";
        }
        cout << "\n";
    }
    return 0;
}
