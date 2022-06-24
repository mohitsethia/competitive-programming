#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
using ll = long long;
const int mod = (int)1e9+7;
void allSubstring(string& s, map<string, int>& mp){
    int n = (int)s.length();
    for(int i = 0; i < n; i++){
        string p = "";
        for(int j = i; j < n; j++){
            p += s[j];
            mp[p]++;
        }
    }
}

ll nCr(int n, int r){
    ll res = 1;
    if(n-r < r){
        r = n-r;
    }
    for(int i = 0; i < r; i++){
        res *= n;
        res /= (i+1);
        res %= mod;
    }
    return res;
}
            
void solve(){
    int n, q;
    string s;
    cin >> n >> q >> s;
    map<string, int> mp;
    allSubstring(s, mp);
    int k;
    while(q--){
        cin >> k;
        ll ans = 0;
        for(auto &it: mp){
            if(k > it.second) continue;
            (ans += nCr(it.second, k)) %= mod;
        }
        cout << ans << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
