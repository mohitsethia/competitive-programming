#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    map<int, int> a, b;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a[x]++;
    }
    int mn = INT_MAX;
    for(auto it: a){
        b[it.second]++;
        mn = min(mn, it.second);
    }
    for(int i = mn+1; i >= 1; i--){
        int ans = 0;
        bool ok = true;
        for(auto p: b){
            int j = p.first;
            if(j%i == 0){
                ans += (j/i)*p.second;
                continue;
            }
            else{
                ans += (j/i + 1)*p.second;
                if(i* (j/i + 1) - j <= j/i + 1){
                    continue;
                }
            }
            ok = false;
            break;
        }
        if(ok){
            cout << ans << "\n";
            return;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
