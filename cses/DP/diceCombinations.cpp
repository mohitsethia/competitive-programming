#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
#define endl '\n'
const int MAX_N = 1e6+1;
const int MOD = 1e9+7;
typedef long long ll;
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    ll n;
    std::cin >> n;
    vector<int> dp(MAX_N+1, 0);
    dp[0] = 1;
    for(int i = 1; i <= MAX_N; i++){
        for(int j = 1; j <= 6; j++){
            if(i-j >= 0){
                dp[i] += dp[i-j];
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}
