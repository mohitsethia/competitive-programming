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
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> v;
        vector<bool> dp(n+1, false);
        ll x;
        ll mx = INT_MIN;
        ll cnt = 0;
        for(ll i = 0; i < 2*n; i++){
            cin >> x;
            if(i == 0) mx = max(mx, x);
            if(x > mx){
                v.emplace_back(cnt);
                mx = x;
                cnt = 1;
            }
            else{
                cnt++;
            }
        }
        v.emplace_back(cnt);
        dp[0] = true;
        for(auto &it: v){
            for(ll i = n; i >= it; i--){
                if(dp[i-it]){
                    dp[i] = true;
                }
            }
        }
        if(dp[n]){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}
