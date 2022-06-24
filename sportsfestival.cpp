#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define int long long
vector<vector<int> > dp(2001, vector<int>(2001, -1));
int solve(int i, int j, vector<int>& s){
    if(i == s.size() || j < 0 || i > j){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    return dp[i][j] = ((s[j]-s[i])+min(solve(i+1, j, s), solve(i, j-1, s)));
}
int32_t main(){
    int n;
    cin >> n;
    vector<int> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    cout << solve(0, n-1, s) << endl;
    return 0;
}
