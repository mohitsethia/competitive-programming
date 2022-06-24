#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> dp(n+1);
    int x;
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        cin >> x;
        int range = min(i+k, n)-max(i-k, 1) + 1;
        if(!x){
            dp[i] = range;
        }
        else{
            if(i-k >= x+k+1){
                dp[i] = dp[x]+range;
            }
            else{
                dp[i] = dp[x] + range - (min(n, x+k)-max(i-k, 1) +1);
            }
        }
        cout << dp[i] << " ";
    }
    return 0;
}
