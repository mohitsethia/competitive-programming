#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long
#define N 1000003
int dp[N];
bool isPrime(int n){
    for(int i = 3; i <= sqrt(n); i += 2){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}
void solve(){
    int x, y;
    scanf("%lld%lld", &x, &y);
    if(dp[x] > y){
        printf("Divyam\n");
        return;
    }
    printf("Chef\n");
}
int32_t main(){
    int t;
    scanf("%lld", &t);
    dp[1] = 0; dp[2] = 1; dp[3] = dp[4] = 2;
    for(int i = 5; i < N; i+=2){
        if(isPrime(i)){
            dp[i] = dp[i-1] + 1;
        }
        else{
            dp[i] = dp[i-1];
        }
        dp[i+1] = dp[i];
    }
    while(t--){
        solve();
    }
    return 0;
}
