#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;
using ll = long long;
bool solve(){
    ll n;
    cin >> n;
    vector<ll> a(2*n);
    map<ll, ll> mp;
    for(ll i = 0; i < 2*n; i++){
        cin >> a[i];
        mp[a[i]]++;
        a[i] /= 2;
    }
    for(auto it: mp){
        if(it.first%2 || it.second != 2){
            return false;
        }
    }
    sort(a.begin(), a.end());
    unique(a.begin(), a.end());
    ll sum = 0;
    set<ll> s;
    for(ll i = n-1; i >= 0; i--){
        ll sd = (a[i]-sum)/(i+1);
        if(sd <= 0 || s.find(sd) != s.end() || (a[i]-sum)%(i+1)){
            return false;
        }
        s.insert(sd);
        sum += sd;
    }
    return true;
}
int main(){
    ll t;
    cin >> t;
    while(t--){
        cout << (solve() ? "YES\n" : "NO\n");
    }
    return 0;
}
