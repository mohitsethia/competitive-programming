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
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<vector<ll> > a(2, vector<ll>(n)), pref(2, vector<ll>(n+1));
        for(ll i = 0; i < 2; i++){
            for(ll j = 0; j < n; j++){
                cin >> a[i][j];
                pref[i][j+1] = pref[i][j]+a[i][j];
            }
        }
        auto points = [&](int row, int l, int r){
            return pref[row][r+1] - pref[row][l];
        };
        ll ans = LLONG_MAX;
        for(ll i = 0; i < n; i++){
            ll bob = max(points(0, i+1, n-1), points(1, 0, i-1));
            ans = min(ans, bob);
        }
        cout << ans << "\n";
    }
    return 0;
}
