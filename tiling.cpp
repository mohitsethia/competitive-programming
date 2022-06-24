//Given a wall of size of 4 X N, and tiles of size (1, 4) and (4, 1).
//In how many ways can you build the wall?

#include<iostream>
#include<vector>
using namespace std;
int numberofways(int n, int *dp){
    if(n <= 3){
        return 1;
    }
    if(dp[n] != 0){
        return dp[n];
    }
    return dp[n] = numberofways(n-1, dp) + numberofways(n-4, dp);
}
int main(){
    int t;
    cin >> t;
    int *dp = new int[100005];
//    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < 100005; i++){
        dp[i] = 0;
    }
    dp[0] = dp[1] = dp[2] = dp[3] = 1;
    while(t--){
        int n;
        cin >> n;
        if(dp[n] == 0){
            numberofways(n, dp);
        }
        cout << dp[n] << endl;
    }
    return 0;
}
/*
#include <iostream>
#define mod 1000000007
using namespace std;

int tiling(int n,int m){
    if(n==m)
        return 2;
    if(1<=n&&n<m)
        return 1;
   

    return (tiling(n-m,m)%mod+tiling(n-1,m)%mod)%mod;
}
int main() {
    int t;
    cin>>t;
   
    while(t--){
        int n,m;
        cin>>n>>m;
        cout<<tiling(n,m)%mod<<endl;
    }
}
*/
