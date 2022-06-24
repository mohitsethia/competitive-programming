#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
#define int long long
void solve(){
    int n;
    cin >> n;
    vector<int> s(n+1), a(n+2, 0);
    for(int i = 1; i <= n; i++){
        cin >> s[i];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(s[i] == 1){
            continue;
        }
        if(i + s[i] > n){
            for(int j = i+2; j <= n; j++){
                a[j]++;
            }
        }
        else{
            for(int j = i+2; j <= i+s[i]; j++){
                a[j]++;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(s[i]-1-a[i] > 0){
            ans += (s[i]-1-a[i]);
        }
        else{
            a[i+1] += (a[i]-s[i]+1);
        }
    }
    cout << ans << "\n";
}
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
