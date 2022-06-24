#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n, l, r;
        cin >> n >> l >> r;
        vector<ll> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        if(n == 1){
            cout << "0\n";
            continue;
        }
        sort(a.begin(), a.end());
        if(a[n-1] + a[n-2] < l || a[0] + a[1] > r){
            cout << "0\n";
            continue;
        }
        ll cnt = 0;
        for(int i = 0; i < n; i++){
            if(a[i] > r){
                break;
            }
            ll p = i+1, q = n;
            if(i < n-1 && (a[i]+a[n-1] < l)){
                continue;
            }
            ll mx = 0, mn = 0;
            while(p <= q){
                ll mid = (p+q)/2;
                if(mid >= n) break;
                if(a[i]+a[mid] >= l && a[i]+a[mid] <= r){
                    p = mid+1;
                    mx = mid;
                }
                else if(a[i]+a[mid] < l){
                    p = mid+1;
                }
                else if(a[i]+a[mid] > r){
                    q = mid-1;
                }
                else{
                    break;
                }
            }
            p = i+1, q = n;
            while(p <= q){
                ll mid = (p+q)/2;
                if(mid >= n) break;
                if(a[i]+a[mid] >= l && a[i]+a[mid] <= r){
                    q = mid-1;
                    mn = mid;
                }
                else if(a[i]+a[mid] < l){
                    p = mid+1;
                }
                else if(a[i]+a[mid] > r){
                    q = mid-1;
                }
                else{
                    break;
                }
            }
            if((mx > 0 && mn > 0)){
                cnt += (mx-mn)+1;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
