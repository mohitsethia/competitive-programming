#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

const int N = 3000;
const int INF = 1e18;

int32_t main(){
    int n;
    cin >> n;
    vector<pair<int, int> > p(n);
    for(int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
    sort(p.begin(), p.end());
    int ans = INF;
    vector<int> dp(n, INF);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        dp[i] += p[i].second;
        int acc = dp[i];
        for(int j = i+1; j < n; j++){
            dp[j] = min(dp[j], acc);
            acc += p[j].first-p[i].first;
        }
        ans = min(ans, acc);
    }
    cout << ans << "\n";
    return 0;
}
