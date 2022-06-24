#include<iostream>
using namespace std;
#define ll long long int
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, a, ans;
        cin >> n;
        if(n <= 2){
            cout << 0 << endl;
        }   
        else{
            a = (n/2) + 1;
            ans = n-a;
            cout << ans << endl;
        }
    }
    return 0;
}
