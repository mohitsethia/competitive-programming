#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

#define int long long
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string h = "hard";
    string s;
    cin >> s;
    vector<int> a(n+1);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<vector<int> > dp(n+2, vector<int> (5, 1e18));
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            int p = s[i] == h[j];
            dp[i+1][j+p] = min(dp[i+1][j+p], dp[i][j]);
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]+a[i]);
        }
    }
    cout << (*min_element(dp[n].begin(), dp[n].begin()+4)) << "\n";
    return 0;
}
