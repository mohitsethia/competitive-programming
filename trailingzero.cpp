#include<iostream>
using namespace std;
#define ll long long int
ll findzero(ll n){
    int ans = 0;
    for(int i = 5; n/i >= 1; i*=5){
        ans += n/i;
    }
    return ans;
}
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        cout << findzero(n) << endl;
    }
    return 0;
}
