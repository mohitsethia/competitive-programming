#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        c[i] = a[i];
    }
    ll mx = 0;
    for(int k = 0; k < n; k++){
        for(int i = k-1; i >= 0; i--){
            if(a[i] > a[i+1]) a[i] = a[i+1];
        }
        for(int i = k+1; i < n; i++){
            if(a[i] > a[i-1]) a[i] = a[i-1];
        }
        ll sum = 0;
        for(int i = 0; i < n; i++){
            sum += a[i];
        }
        if(sum > mx){
            mx = sum;
            for(int i = 0; i < n; i++){
                b[i] = a[i];
            }
        }
        for(int i = 0; i < n; i++){
            a[i] = c[i];
        }
    }
    for(int i = 0; i < n; i++){
        cout << b[i] << " ";
    }
    return 0;
}
