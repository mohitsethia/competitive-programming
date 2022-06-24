#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
const int N = 2e5+5;
vector<vector<int> > dp(N, vector<int>(2));
int solve(vector<int>& a, int& n, int i, int flag){
    if(i == n) return 0;
    if(i == n-1){
        if(flag){
            //friend's turn
            return a[i];
        }
        else{
            //our turn
            return 0;
        }
    }
    if(dp[i][flag] != -1){
        return dp[i][flag];
    }
    int ans = INT_MAX;
    if(flag == 1){
        int ans1 = a[i]+solve(a, n, i+1, 0);
        int ans2 = a[i]+a[i+1]+solve(a, n, i+2, 0);
        ans = min(ans1, ans2);
    }
    else{
        int ans1 = solve(a, n, i+1, 1);
        int ans2 = solve(a, n, i+2, 1);
        ans = min(ans1, ans2);
    }
    return dp[i][flag] = ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            dp[i][0] = dp[i][1] = -1;
        }
        cout << solve(a, n, 0, 1) << "\n";
    }
    return 0;
}
