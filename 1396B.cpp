#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll mx = 0, sum = 0;
        ll x;
        for(ll i = 0; i < n; i++){
            cin >> x;
            mx = max(mx, x);
            sum += x;
        }
        if(mx*2 > sum || (sum%2)){
            cout << "T\n";
        }
        else{
            cout << "HL\n";
        }
    }
    return 0;
}
