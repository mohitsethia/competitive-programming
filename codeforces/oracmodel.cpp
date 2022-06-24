#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define ll long long int
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll a[n+1], f[n+1];
        for(ll i = 1; i <= n ; i++){
            cin >> a[i];
            f[i] = 1;
        }
        for(ll i = 1; i <= n; i++){
            for(ll j = i*2; j <= n; j += i){
                if(a[i] < a[j]){
                    f[j] = max(f[j], f[i]+1);
                }
            }
        }
        ll mx = 1;
        for(int i = 1; i <= n; i++){
            mx = max(mx, f[i]);
        }
        cout << mx << endl;
    }
    return 0;
}

