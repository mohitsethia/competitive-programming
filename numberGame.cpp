#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
const ll N = 2e5;
bool isPrime(ll n){
    if(n == 3){
        return true;
    }
    for(int i = 2; i < min(N, n); i += 1+(i&1)){
        if(n%i == 0)
            return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        if(n == 1){
            cout << "FastestFinger\n";
            continue;
        }
        if(n%2 || n == 2){
            cout << "Ashishgup\n";
            continue;
        }
        ll cnt2 = 0;
        //n&n-1 check if n is 2^x
            if((n%4 != 0 && isPrime(n/2)) || (n&(n-1)) == 0){
                cout << "FastestFinger\n";
            }
            else{
                cout << "Ashishgup\n";
            }
    }
    return 0;
}
