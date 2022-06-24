#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
   // cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> a(n);
        for(ll i = 0; i < n; i++){
            cin >> a[i];
        }
        unordered_map<ll, vector<pair<ll, ll> > > mp;
        for(ll i = 0; i < min(n, 4001ll); i++){
            for(ll j = i+1; j < min(n, 4001ll); j++){
                ll sum = a[i]+a[j];
                if(mp.find(sum) != mp.end()){
                    for(auto it: mp[sum]){
                        ll p = it.first, q = it.second;
                        if(p != i && p != j && q != i && q != j){
                            cout << "YES\n";
                            cout << i+1 << " " << j+1 << " " << p+1 << " " << q+1 << "\n";
                            return 0;
                        }
                    }
                }
                else{
                    mp[sum].emplace_back(make_pair(i, j));
                }
            }
        }
        cout << "NO\n";
    }
    return 0;
}
