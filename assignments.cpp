#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
#define int long long
int assign(int n, vector<vector<int> >& pref){
    int mx = 1 << n;
    vector<int> dp(mx, 0);
    dp[mx-1] = 1;
    for(int mask = mx-1; mask >= 0; mask--){
        int j = mask;
        int s = 0;
        while(j){
            s += (j&1);
            j /= 2;
        }
        for(int i = 0; i < n; i++){
            if(pref[s][i] && !(mask & (1 << i))){
                dp[mask] += dp[mask | (1 << i)];
            }
        }
    }
    return dp[0];
}
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int> > pref(n+1, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> pref[i][j];
            }
        }
        cout << assign(n, pref) << endl;
    }
    return 0;
}
