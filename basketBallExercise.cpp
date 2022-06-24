#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<pair<ll, ll> > h(n), dp(n);
    for(int i = 0; i < n; i++){
        cin >> h[i].first;
    }
    for(int j = 0; j < n; j++){
        cin >> h[j].second;
    }
    for(int i = 0; i < n; i++){
        dp[i].first = h[i].first;
        dp[i].second = h[i].second;
        if(i == 1){
            dp[i].first = max(dp[i].first, dp[i].first+dp[i-1].second);
            dp[i].second = max(dp[i].second, dp[i].second+dp[i-1].first);
        }
        else if(i > 1){
            dp[i].first = max(dp[i].first, max(dp[i-1].second+dp[i].first, dp[i-2].second+dp[i].first));
            dp[i].second = max(dp[i].second, max(dp[i-1].first+dp[i].second, dp[i-2].first+dp[i].second));
        }
    }
    cout << max(dp[n-1].first, dp[n-1].second) << endl;
    return 0;
}
