#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
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
        ll sum  = 0;
        vector<ll> v(n);
        for(int i = 0; i < n; i++){
            ll x;
            cin >> x;
            sum += x;
            mp[x]++;
            v[i] = x;
        }
        if(sum % n != 0){
            cout << "-1\n";
        }
        else{
            if(mp.size() == 1){
                cout << "0\n";
            }
            else{
                sum = sum/n;
                int cnt = 0;
                for(auto it: v){
                    if(it > sum) cnt++;
                }
                cout << cnt << "\n";
            }
        }
    }
    return 0;
}
