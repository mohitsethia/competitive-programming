#include<iostream>
#include<vector>
using namespace std;
#define ll long long int
bool sqseq(ll x){
    if(x%4 == 2){
        return false;
    }
    return true;
}
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll a[n], count = 0;
        for(ll i = 0; i < n; i++){
            cin >> a[i];
            if(sqseq(a[i]) == true){
                count++;
            }
        }
        ll ans = 1;
        for(ll i = 0; i < n - 1; i++){
            ans = a[i];
            for(ll j =i+1; j < n; j++){
                ans *= a[j];
                if(sqseq(ans) == true){
                count++;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}
