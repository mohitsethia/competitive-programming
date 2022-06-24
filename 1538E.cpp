#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>
using namespace std;
using ll = long long;
ll n;
pair<ll, string> shrink(string s, ll m){
    ll ans = 0;
    ll l = max(0ll, m-2);
    ll r = min((ll)s.length()-1, m);
    for(ll i = l; i <= r; i++){
        if(i+4 <= (ll)s.length() && s.substr(i, 4) == "haha"){
            ans++;
        }
    }
    pair<ll, string> res;
    if(s.length() <= 10){
        res.second = s;
    }
    else{
        res.second = s.substr(0, 5) + s.substr(s.length()-5, 5);
    }
    res.first = ans;
    return res;
}

void solve(){
    map<string, pair<ll, string> > mp;
    cin >> n;
    string last;
    for(ll i = 0; i < n; i++){
        string a, b, c, d, e;
        cin >> a >> b >> c;
        last = a;
        if(b == ":="){
            mp[a] = shrink(c, c.length()/2);
        }
        else{
            cin >> d >> e;
            pair<ll, string> x = mp[c], y = mp[e];
            ll ans = x.first + y.first;
            pair<ll, string> z = shrink(x.second+y.second, x.second.length()-1);
            mp[a] = make_pair(ans+z.first, z.second);
        }
    }
    cout << mp[last].first << "\n";
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
