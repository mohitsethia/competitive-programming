#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll cnt = 1;
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    for(ll i = 1; i < n; i++){
        if(a[i]-a[i-1] > x){
            ll temp = (a[i]-a[i-1]-1)/x;
            pq.push(temp);
        }
    }
    while(pq.size() > 0){
        ll temp = pq.top();
        if(temp <= k){
            k -= temp;
            pq.pop();
        }
        else{
            break;
        }
    }
    cnt = (int)pq.size()+1;
    cout << cnt << endl;
    return 0;
}
