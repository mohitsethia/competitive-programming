#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    //cin >> t;
    while(t--){
        ll n, q;
        string s;
        cin >> n >> q >> s;
        vector<vector<ll> > ans(6, vector<ll>(n+1));
        vector<string> permutation = {"abc", "acb", "bac", "bca", "cab", "cba"};
        vector<string> vals(6, "");
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < 6; j++){
                vals[j] += permutation[j][i%3];
            }
        }
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < 6; j++){
                ll prev = (i > 0 ? ans[j][i-1] : 0);
                ans[j][i] = prev + (s[i] != vals[j][i]);
            }
        }
        while(q--){
            ll l, r;
            cin >> l >> r;
            r--, l--;
            ll res = LLONG_MAX;
            for(ll i = 0; i < 6; i++){
                ll dis1 = ans[i][r];
                ll dis2 = (l > 0 ? ans[i][l-1] : 0);
                res = min(res, dis1-dis2);
            }
            cout << res << "\n";
        }
    }
    return 0;
}
