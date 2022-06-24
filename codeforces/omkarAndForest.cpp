#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
const int MOD = (int)1e9 + 7;

void solve(){
    int n, m;
    cin >> n >> m;
    char c;
    ll ans = 1ll;
    bool present = false;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> c;
            if(c == '0'){
                present = true;
            }
            else{
                (ans *= 2ll) %= MOD;
            }
        }
    }
    if(present) cout << ans << endl;
    else cout << ans-1 << endl;
}
int main(){
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
