#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<climits>
#include<queue>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int> > pq;
    int sum = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        sum += x;
        pq.push(x);
        while(sum < 0){
            sum -= pq.top();
            pq.pop();
        }
    }
    cout << (int)pq.size() << endl;

    /*
    vector<int> a(n+1), dp(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        dp[i] = INT_MIN;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i; j >= 1; j--){
            if(dp[j-1] + a[i] >= 0){
                dp[j] = max(dp[j-1]+a[i], dp[j]);
            }
        }
    }
    for(int i = 0; i <= n;i++){
        cout << dp[i] << " ";
    }
    for(int i = n; i >= 0; i--){
        if(dp[i] >= 0){
            cout << i << endl;
            return 0;
        }
    }
    */
    return 0;
}
