#include<iostream>
using namespace std;
#define ll long long int
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll ans = (((n-1)/2)*(((n-1)/2)+1)*(2*((n-1)/2)+1)) / 6;
        cout << ans * 8 << endl;
    }
    return 0;
}
