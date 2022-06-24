#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

#define int long long
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e5+1;

int fact[N];

void factorial(){
    fact[0] = fact[1] = 1;
    for(int i = 2; i < N; i++){
        fact[i] = (i*fact[i-1]) % MOD;
    }
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = 1, rem = 0;
        map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[a[i]]++;
        }
        for(int i = 0; i < n; i++){
            if(mp[i] == 0) break;
            (ans *= mp[i]) %= MOD;
            rem++;
        }
        (ans *= fact[n-rem]) %= MOD;
        cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    factorial();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
