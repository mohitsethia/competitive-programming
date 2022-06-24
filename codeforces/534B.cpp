#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int v1, v2;
    cin >> v1 >> v2;
    int t, d;
    cin >> t >> d;
    vector<int> dp1(t+1), dp2(t+1);
    dp1[1] = v1;
    dp2[t] = v2;
    for(int i = 2; i <= t; i++){
        dp1[i] = dp1[i-1]+d;
    }
    for(int i = t-1; i >= 1; i--){
        dp2[i] = dp2[i+1]+d;
    }
    long long ans = 0;
    for(int i = 1; i <= t; i++){
        ans += min(dp1[i], dp2[i]);
    }
    cout << ans << endl;
    return 0;
}
