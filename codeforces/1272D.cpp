#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n), left(n, 1), right(n, 1);
    ll ans = 1;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    for(ll i = 1; i < n; i++){
        if(a[i] > a[i-1]){
            left[i] = left[i-1] + 1;
            ans = max(ans, left[i]);
        }
    }
    for(int i = n-2; i >= 0; i--){
        if(a[i] < a[i+1]){
            right[i] = right[i+1]+1;
            ans = max(ans, right[i]);
        }
    }
    for(int i = 0; i < n-2; i++){
        if(a[i] < a[i+2]){
            ans = max(ans, left[i]+right[i+2]);
        }
    }
    cout << ans << endl;
    return 0;
}
