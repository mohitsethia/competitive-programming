#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<climits>
#define endl '\n'
typedef long long ll;
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    ll n, m, x, y;
    std::cin >> n >> m >> x >> y;
    std::vector<std::string> s(n);
    for(int i = 0; i < n; i++){
        std::cin >> s[i];
    }
    std::vector<std::pair<ll, ll> > v(1);
    v[0] = {0, 0};
    for(ll j = 0; j < m; j++){
        ll cnt1 = 0, cnt2 = 0;
        for(ll i = 0; i < n; i++){
            if(s[i][j] == '#'){
                cnt1++;
            }
            else{
                cnt2++;
            }
        }
        v.push_back({cnt1, cnt2});
        v[j+1].first += v[j].first;
        v[j+1].second += v[j].second;
    }
    std::vector<std::vector<ll> > dp(m+1, std::vector<ll>(2, INT_MAX));
    dp[0][0] = dp[0][1] = 0;
    for(ll i = 1; i <= m; i++){
        for(ll k = x; k <= y; k++){
            if(i-k >= 0){
                dp[i][0] = std::min(dp[i-k][1] + v[i].first - v[i-k].first, dp[i][0]);
                dp[i][1] = std::min(dp[i-k][0] + v[i].second - v[i-k].second, dp[i][1]);
            }
        }
    }
    std::cout << std::min(dp[m][0], dp[m][1]);
    return 0;
}
