#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, l, r, ql, qr;
    cin >> n >> l >> r >> ql >> qr;
    vector<int> preSum(n+1), a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        preSum[i+1] = preSum[i] + a[i];
    }
    int ans = INT_MAX;
    for(int i = 0; i <= n; i++){
        int curr = preSum[i]*l + (preSum[n]- preSum[i])*r;
        if(i > n-i){
            curr += (i - (n-i) - 1)*ql;
        }
        if(i < n-i){
            curr += ((n-i) - i - 1)*qr;
        }
        ans = min(ans, curr);
    }
    cout << ans << endl;
    return 0;
}
