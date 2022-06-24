#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<numeric>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(ll &x: a){
        cin >> x;
    }
    vector<pair<ll, ll> > memo(n, {-1, -1});
    ll currSum = accumulate(end(a)-k, end(a), 0);
    memo[n-k] = {currSum, n-k};
    for(ll i = n-k-1; i >= 0; i--){
        currSum -= a[i+k];
        currSum += a[i];
        memo[i] = max(memo[i+1], {currSum, i});
        if(memo[i+1].first == currSum){
            memo[i].second = i;
        }
    }
    currSum = accumulate(begin(a), begin(a)+k, 0);
    pair<ll, ll> ans(0, memo[k].second);
    ll mx = currSum + memo[k].first;
    for(ll i = 1; i <= n-2*k; i++){
        currSum += a[i+k-1];
        currSum -= a[i-1];
        if(mx < currSum + memo[i+k].first){
            ans = {i, memo[i+k].second};
            mx = currSum + memo[i+k].first;
        }
    }
    cout << ans.first+1 << " " << ans.second+1 << "\n";
    return 0;
}
