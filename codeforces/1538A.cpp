#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
#define endl '\n'
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> a(n);
        ll idx_one = -1, idx_n = -1;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] == 1) idx_one = i;
            if(a[i] == n) idx_n = i;
        }
        if(n == 2){
            cout << "2\n";
            continue;
        }
        if(idx_one <= (n-1)/2 && idx_n <= (n-1)/2){
            cout << max(idx_one, idx_n)+1 << endl;
            continue;
        }
        else if(idx_one >= n/2 && idx_n >= n/2){
            cout << n- min(idx_one, idx_n) << endl;
            continue;
        }
        else{
            ll ans = (n-idx_n)+idx_one+1;
            ans = min(ans, (n-idx_one)+idx_n+1);
            int temp = max((n-idx_n), (n-idx_one));
            if(temp < ans){
                ans = temp;
            }
            temp = max(idx_one, idx_n)+1;
            if(temp < ans){
                ans = temp;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
