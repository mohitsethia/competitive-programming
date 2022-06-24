#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> pref(n+1);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        pref[i+1] = pref[i] + a[i];
    }
    vector<vector<int > > dp(n+1, vector<int>(n+1));
    for(int p = 1; p < n; p++){
        for(int i = 1; i < n-p+1; i++){
            int len = i+p;
            int sum = pref[len]-pref[i-1];
            dp[i][len] = INT_MAX;
            for(int j = i; j < len; j++){
                dp[i][len] = min(dp[i][len], dp[i][j]+dp[j+1][len]+sum);
            }
        }
    }
    cout << dp[1][n] << "\n";
    return 0;
}
