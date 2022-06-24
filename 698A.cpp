#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
using ll = long long;
vector<vector<int> > dp(105, vector<int>(3, -1));
int solve(vector<int>& a, int& n, int i, int lastActivity){
    if(i >= n) return 0;
    if(dp[i][lastActivity] != -1){
        return dp[i][lastActivity];
    }
    if(a[i] == 0){
        dp[i][lastActivity] = solve(a, n, i+1, 0) + 1;
    }
    else if(a[i] == 1){
        if(lastActivity == a[i]){
            dp[i][lastActivity] = solve(a, n, i+1, 0) + 1;
        }
        else{
            dp[i][lastActivity] = solve(a, n, i+1, 1);
        }
    }
    else if(a[i] == 2){
        if(lastActivity == a[i]){
            dp[i][lastActivity] = solve(a, n, i+1, 0) + 1;
        }
        else{
            dp[i][lastActivity] = solve(a, n, i+1, 2);
        }
    }
    else if(a[i] == 3){
        int x = ((lastActivity == 1) ? INT_MAX : solve(a, n, i+1, 1));
        int y = ((lastActivity == 2) ? INT_MAX : solve(a, n, i+1, 2));
        dp[i][lastActivity] = min(x, y);
    }
    return dp[i][lastActivity];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << solve(a, n, 0, 0) << endl;
    return 0;
}
