#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
void solve(){
    ll A, B, n;
    cin >> A >> B >> n;
    vector<pair<ll, ll> > a(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i].first;
    }
    for(ll i = 0; i < n; i++){
        cin >> a[i].second;
    }
    sort(a.begin(), a.end());
    for(ll i = 0; i < n; i++){
        if(B <= 0){
            cout << "NO\n";
            return;
        }
        ll heroAttacks = a[i].second/A + (a[i].second%A == 0 ? 0 : 1);
        ll monster = B/a[i].first + (B%a[i].first == 0 ? 0 : 1);
        if(heroAttacks <= monster){
            B -= a[i].first*heroAttacks;
            a[i].second -= A*heroAttacks;
            continue;
        }
        else{
            cout << "NO\n";
            return;
        }
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
