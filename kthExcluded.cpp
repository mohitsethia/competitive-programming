#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define endl '\n'
using namespace std;
using ll = long long;
int main(){
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    while(q--){
        ll k;
        cin >> k;
        ll low = 0;
        ll high = n-1;
        ll mid;
        while(low <= high){
            mid = low + (high-low)/2;
            if(a[mid] - (1+mid) < k)
                low = mid+1;
            else
                high = mid-1;
        }
        cout << low + k << endl;
    }
    return 0;
}
