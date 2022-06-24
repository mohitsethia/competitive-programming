#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<ll> ans(n);
    ll curr = 0;
    for(ll i = 0; i < n; i++){
        curr += a[i];
        ans[i] = curr;
        if(i >= k){
            ans[i] += ans[i-k];
        }
        cout << ans[i] << " ";
    }
    return 0;
}
