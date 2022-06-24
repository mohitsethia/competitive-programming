#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
void solve(){
    int n, k;
    cin >> n >> k;
    int height[n];
    for(int i = 0; i < n; i++){
        cin >> height[i];
    }
    int mx = *max_element(height, height+n);
    if(n*mx < k){
        cout << "-1\n";
        return;
    }
    int ans = n+1;
    for(int b = 0; b < k; b++){
        int to = -2;
        for(int i = 0; i < n-1; i++){
            if(height[i] < height[i+1]){
                to = i;
                break;
            }
        }
        ans = to+1;
        if(to == -2){
            break;
        }
        height[to]++;
    }
    cout << ans << endl;
    return;
}
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
