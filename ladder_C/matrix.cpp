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
    ll a;
    cin >> a;
    string s;
    cin >> s;
    ll n = s.length();
    ll tot_zero = 0, tot_non_zero = 0;
    map<ll, ll> mp;
    for(int i = 0; i < n; i++){
        ll sum = 0;
        for(int j = i; j < n; j++){
            sum += s[j]-'0';
            if(sum == 0) tot_zero++;
            else tot_non_zero++;
            mp[sum]++;
        }
    }
    if(a == 0){
        ll ans = 2*tot_zero*tot_non_zero;
        ans += (tot_zero*(tot_zero-1));
        ans += mp[0];
        cout << ans << endl;
        return 0;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll sum = 0;
        for(int j = i; j < n; j++){
            sum += s[j]-'0';
            if(sum == 0) continue;
            if(a%sum == 0){
                if(mp.find(a/sum) != mp.end()){
                    ans += mp[a/sum];
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
