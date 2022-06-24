#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k, z;
        cin >> n >> k >> z;
        vector<int> a(n+1), prefix(n+1);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            prefix[i] = prefix[i-1]+a[i];
        }
        int ans = 0;
        for(int i = 2; i <= n; i++){
            int req = i-1;
            if(req > k) break;
            int rem = k-req;
            int total = min(rem, 2*z);
            int x = a[i] + a[i-1];
            int score = (total/2)*x + (total%2)*a[i-1];
            score += prefix[i];
            rem -= total;
            score += prefix[i+rem]-prefix[i];
            ans = max(ans, score);
        }
        cout << ans << endl;
    }
    return 0;
}
