#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> a(n);
        for(ll i = 0; i < n; i++){
            cin >> a[i];
        }
        map<ll, ll> mp;
        for(ll i = 0; i < (1 << n); i++){
            ll sum = 0;
            for(ll j = 0; j < n; j++){
                if((i&(1<<j))){
                    sum += a[j];
                }
            }
            mp[sum]++;
        }
        bool found = false;
        for(auto it: mp){
            if(it.second > 1){
                found = true;
                break;
            }
        }
        if(found){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}
