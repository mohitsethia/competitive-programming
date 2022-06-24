#include<iostream>
#include<vector>
using namespace std;
#define mod 1000000007
long long int dp[100005];
long long prep[100005];
int k;
int getAns(int n){
    if(n == 0){
        return 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int ans = 0;
    if(n >= k){
        ans += getAns(n-k), ans = ans % mod;
    }
    ans += getAns(n-1), ans = ans % mod;
    return dp[n] = ans;
}
void find(){
    for(int i = 0; i < 100005; i++){
        dp[i] = -1;
    }
    for(int i = 1; i < 100005; i++){
        prep[i] = (prep[i-1] + getAns(i));
    }
}
int32_t main(){
    int t;
    cin >> t >> k;
    find();
    while(t--){
        int a, b, sum = 0;
        cin >> a >> b;
        
//        for(int i = a; i <= b; i++){
//            sum += getAns(i);
//        }
        cout << (prep[b] - prep[a-1] + mod)%mod << endl;
//        cout << sum << endl;
    }
    return 0;
}
