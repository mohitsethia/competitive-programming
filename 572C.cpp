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
    vector<ll> dp(n+1);
    ll x;
    for(int i = 1; i <= n; i++){
        cin >> x;
        dp[i] = dp[i-1] + x;
    }
    ll q, l, r;
    cin >> q;
    while(q--){
        cin >> l >> r;
        cout << (dp[r]-dp[l-1])/10 << "\n";
    }
    return 0;
}








/*
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
    vector<ll> a(n);
    vector<vector<pair<ll, ll> > > dp(20);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        dp[0].emplace_back(make_pair(a[i], 0ll));
    }
    ll curr = 1;
    for(int deg = 1; deg < 20; deg++){
        curr *= 2;
        for(int i = 0; i+curr <= n; i++){
            ll left1 = dp[deg-1][i].first;
            ll left2 = dp[deg-1][i+curr/2].first;
            ll candies1 = dp[deg-1][i].second;
            ll candies2 = dp[deg-1][i+curr/2].second;
            ll resultingCandies = candies1 + candies2;
            ll res_left = (left1 + left2) % 10;
            if(left1 + left2 >= 10) resultingCandies++;
            dp[deg].emplace_back(make_pair(res_left, resultingCandies));
        }
    }
    ll q;
    cin >> q;
    while(q--){
        ll l, r;
        cin >> l >> r;
        ll len = r-l+1;
        ll deg = 0;
        while(len%2 == 0){
            deg++, len /= 2;
        }
        cout << dp[deg][l-1].second << "\n";
    }
    return 0;
}
*/
