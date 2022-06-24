#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        vector<ll> v(n);
        for(ll &i: v){
            cin >> i;
        }
        vector<ll> a, b;
        for(ll i: v){
            int x;
            cin >> x;
            if(x == 1){
                a.emplace_back(i);
            }
            else{
                b.emplace_back(i);
            }
        }
        sort(a.begin(), a.end(), greater<ll>());
        sort(b.begin(), b.end(), greater<ll>());
        ll j = b.size();
        ll sum_A = 0ll, sum_B = 0ll;
        sum_B = accumulate(b.begin(), b.end(), 0ll);
        sum_A = accumulate(a.begin(), a.end(), 0ll);
        if(sum_A < m){
            cout << "-1\n";
            continue;
        }
        sum_A = 0ll;
        ll ans = LLONG_MAX;
        for(int i = 0; i <= (int)a.size(); i++){
            while(j > 0 && sum_A+sum_B-b[j-1] >= m){
                j--;
                sum_B -= b[j];
            }
            if(sum_A + sum_B >= m){
                ans = min(ans, 2ll*j+i);
            }
            if(i != (ll)a.size()){
                sum_A += a[i];
            }
        }
        cout << (ans == LLONG_MAX ? -1ll : ans) << "\n";
    }
    return 0;
}
