#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<climits>
using namespace std;
typedef long long ll;
bool canSatisfy(ll mid, vector<ll>& a){
    int n = a.size();
    ll supervisors = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > mid){
            return false;
        }
        supervisors += (mid - a[i]);
        if(supervisors >= mid){
            return true;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0, mx = INT_MIN;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        mx = max(mx, a[i]);
    }
    ll low = mx;
    ll high = sum;
    ll ans = sum;
    while(low <= high){
        ll mid = low + (high - low)/2;
        if(canSatisfy(mid, a)){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    cout << ans << endl;
    return 0;
}
