#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
void solve(){
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), pref, ind;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        if(pref.empty() || sum > pref.back()){
            pref.push_back(sum);
            ind.push_back(i);
        }
    }
    for(int q = 0; q < m; q++){
        ll x;
        cin >> x;
        if(pref.back() < x && sum <= 0){
            cout << "-1 ";
            continue;
        }
        ll needTimes = 0;
        if(pref.back() < x){
            needTimes = (x - pref.back() + sum -1)/sum;
        }
        x -= needTimes*sum;
        ll ans = needTimes*n + ind[lower_bound(pref.begin(), pref.end(), x)-pref.begin()];
        cout << ans << " ";
    }
    cout << endl;
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
