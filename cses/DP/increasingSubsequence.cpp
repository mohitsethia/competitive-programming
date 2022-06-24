#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
using ll = long long;
void IncreasingSeq(vector<ll> &a, ll &n){
    vector<ll> dp(n+1, INT_MAX);
    dp[0] = INT_MIN;
    for(ll i = 0; i < n; i++){
        ll idx = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        if(dp[idx] > a[i] && dp[idx-1] < a[i]){
            dp[idx] = a[i];
        }
    }
    for(ll i = n; i > 0; i--){
        if(dp[i] != INT_MAX){
            cout << i << "\n";
            return;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    IncreasingSeq(a, n);
    return 0;
}
