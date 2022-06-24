#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
struct job{
    ll start, end, money;
};
ll find(job a[], ll &i){
    ll low = 0, high = i;
    ll ans = -1;
    while(low <= high){
        ll mid = (low+high)/2;
        if(a[mid].end < a[i].start){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    job a[n];
    for(ll i = 0; i < n; i++){
        cin >> a[i].start >> a[i].end >> a[i].money;
    }
    sort(a, a+n, [&](job &p, job &q){
        return p.end < q.end;
    });
    vector<ll> dp(n);
    dp[0] = a[0].money;
    for(ll i = 1; i < n; i++){
        dp[i] = 0;
        ll temp = a[i].money;
        ll search = find(a, i);
        if(search != -1) temp += dp[search];
        dp[i] = max(dp[i-1], temp);
    }
    cout << dp[n-1] << "\n";
    return 0;
}
