#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;
#define ll long long int
ll countbits(ll left, ll right){
    while((left | (left+1)) <= right){
        left |= left + 1;
    }
    return left;
}
int main(){
//    auto start = high_resolution_clock::now();
    int t;
    cin >> t;
    while(t--){
        ll x, y, l, r;
        cin >> x >> y >> l >> r;
        ll ans = 0, k = 0;
        for(ll i = r; i >= l; i--){
            ll a = (x & i);
            ll b = (y & i);
            if((a*b) > ans){
                ans = a*b;
                k = i;
            }
        }
/*
        ll count = countbits(l, r);
*/
        cout << k << endl;
    }
//    auto stop = high_resolution_clock::now();
//    auto duration = duration_cast<microseconds>(stop - start);
//    cout << duration.count() << endl;
    return 0;
}
