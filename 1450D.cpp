#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
vector<ll> arr;
bool is_perm(vector<ll> &a){
    ll n = a.size();
    vector<ll> f(n+1);
    for(ll i = 0; i < n; i++){
        if(a[i] > 0 && a[i] <= n)
            f[a[i]] = 1;
    }
    for(ll i = 1; i <= n; i++){
        if(!f[i]){
            return false;
        }
    }
    return true;
}
bool check(ll k){
    vector<ll> ans;
    deque<ll> q;
    ll n = arr.size();
    for(ll i = 0; i < n; i++){
        while(q.size() && q.front() <= i-k){
            q.pop_front();
        }
        while(q.size() && arr[q.back()] >= arr[i]){
            q.pop_back();
        }
        q.push_back(i);
        if(i >= k-1){
            ans.push_back(arr[q.front()]);
        }
    }
    return is_perm(ans);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        arr.resize(n);
        for(ll i = 0; i < n; i++){
            cin >> arr[i];
        }
        string ans = "";
        if(is_perm(arr)){
            ans += '1';
        }
        else{
            ans += '0';
        }
        ll l = 2, r = n, res = n+1;
        while(l <= r){
            ll mid = (l+r)/2;
            if(check(mid)){
                res = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        for(ll i = 2; i <= n; i++){
            if(i < res){
                ans += '0';
            }
            else{
                ans += '1';
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
