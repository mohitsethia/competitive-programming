#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

int calc(string &u, int x){
    string v = to_string(x);
    int len = 0;
    for(int i = 0; i < (int)u.size(); i++){
        if(len < (int)v.size() && u[i] == v[len]){
            len++;
        }
    }
    return (((int)u.size()-len) + ((int)v.size()-len));
}

void solve(){
    int n;
    cin >> n;
    int ans = 21;
    string u = to_string(n);
    for(int i = 1; i <= (1ll << 61); i <<= 1){
        ans = min(ans, calc(u, i));
    }
    cout << ans << "\n";
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
