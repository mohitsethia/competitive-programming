#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<climits>
using namespace std;
#define endl '\n'

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    for(int i = 0; i <= n; i++){
        for(char c: to_string(i)){
            int digit = c-'0';
            if(digit <= i){
                dp[i] = min(dp[i], dp[i-digit]+1);
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}
