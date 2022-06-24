#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<climits>

using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        map<ll, ll> mp;
        ll mn = LLONG_MAX;
        ll x;
        bool isTrue = false;
        for(ll i = 0; i < n; i++){
            cin >> x;
            mp[x]++;
            mn = min(mn, x);
        }
        int cnt = mp.begin()->second;
        for(auto it: mp){
            if(it.first != mn && it.first <= mn * 2){
                isTrue = true;
                break;
            }
        }
        if(isTrue){
            cout << n << "\n";
        }
        else{
            cout << n-cnt << "\n";
        }
    }
    return 0;
}

