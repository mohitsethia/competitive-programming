#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        map<ll, ll> cnt;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i]%k){
                cnt[k-a[i]%k]++;
            }
        }
        ll mx = -1;
        for(auto it: cnt){
            ll z = it.first;
            if(it.second > 1){
                z += (it.second-1)*k;
            }
            mx = max(mx, z);
        }
        cout << mx+1 << endl;
    }
    return 0;
}























/*
#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
int presum[200000] = {0};
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int arr[n], modular[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];  
            modular[i] = k - arr[i]%k;
            if(modular[i] == k){
                modular[i] = 0;
            }
        }
        int maxx = 1, maxval = 0, curcount = 1;
        sort(modular, modular+n);
        for(int i = 0; i < n; i++){
            if(modular[i] != 0 && modular[i] == modular[i+1]){
                curcount++;
            }
            else{
                if(curcount >= maxx && modular[i] != 0){
                    maxx = curcount;
                    maxval = modular[i];
                }
                curcount = 1;
            }
        }
        if(curcount >= maxx && modular[n-1] != 0){
            maxx = curcount;
            maxval = modular[n-1];
        }
        if(maxval == 0){
            cout << 0 << endl;
        }
        else{
            cout << (maxx-1)*k + maxval+1 << endl;
        }
    }
    return 0;
}
*/
