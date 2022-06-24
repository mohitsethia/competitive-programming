#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
/*
int solve(vector<int>& price, vector<int>& pages, int x, int n, int i){
    if(x < 0){
        return 0;
    }
    if(n == -1){
        return i;
    }
    return max(solve(price, pages, x, n-1, i), solve(price, pages, x-price[n], n-1, i+pages[n]));
}
*/
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> price(n+1), pages(n+1);
    for(int i = 1; i <= n; i++){
        cin >> price[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> pages[i];
    }
    vector<vector<int> > dp(n+1, vector<int> (x+1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= x; j++){
            dp[i][j] = max(dp[i-1][j], (j >= price[i]) ? dp[i-1][j-price[i]] + pages[i] : 0);
        }
    }
    cout << dp[n][x];
    return 0;
}
