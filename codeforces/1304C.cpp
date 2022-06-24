#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;

void solve(){
    ll n, m;
    cin >> n >> m;
    vector<ll> t(n), l(n), h(n);
    for(int i = 0; i < n; i++){
        cin >> t[i] >> l[i] >> h[i];
    }
    ll mn = m, mx = m;
    ll prevTime = 0;
    for(int i = 0; i < n; i++){
        mn -= t[i] - prevTime;
        mx += t[i] - prevTime;
        if(mx < l[i] || mn > h[i]){
            cout << "NO\n";
            return;
        }
        mn = max(mn, l[i]);
        mx = min(mx, h[i]);
        prevTime = t[i];
    }
    cout << "YES\n";
    return;
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
