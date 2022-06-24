#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 2e5+2;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int dp[N] = {0};
        int cnt[N] = {0};
        int x;
        for(int i = 0; i < n; i++){
            cin >> x;
            cnt[x]++;
        }
        for(int i = 1; i < N; i++){
            dp[i] += cnt[i];
            for(int j = 2*i; j < N; j += i){
                dp[j] = max(dp[i], dp[j]);
            }
        }
        cout << (n-*max_element(dp, dp+N)) << "\n";
    }
    return 0;
}
