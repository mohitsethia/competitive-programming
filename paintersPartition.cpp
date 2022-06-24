#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool isPossible(int *a, int n, int k, int curr_min){
    int curr_sum = 0;
    int req = 1;
    for(int i = 0; i < n; i++){
        if(a[i] > curr_min){
            return false;
        }
        if(curr_sum + a[i] > curr_min){
            curr_sum = a[i];
            req++;
            if(req > k) return false;
        }
        else{
            curr_sum += a[i];
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n], sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    int low = 0, high = sum;
    int ans = 0;
    while(low <= high){
        int mid = (high+low)/2;
        if(isPossible(a, n, k, mid)){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    cout << ans << "\n";
    return 0;
}























/*
#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1);
    vector<int> sum(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    vector<vector<int> > dp(k+1, vector<int>(n+1));
    for(int i = 1; i <= n; i++){
        dp[1][i] = sum[i];
    }
    for(int i = 1; i <= k; i++){
        dp[i][1] = sum[1];
    }
    int ans = INT_MAX;
    for(int i = 2; i <= k; i++){
        for(int j = 2; j <= n; j++){
            ans = INT_MAX;
            for(int p = 1; p <= j; p++){
                ans = min(ans, max(dp[i-1][p], sum[j]-sum[p]));
            }
            dp[i][j] = ans;
        }
    }
    cout << dp[k][n] << endl;
    return 0;
}
*/
