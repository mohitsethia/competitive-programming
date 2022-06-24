#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, m, k;
        cin >> n >> m >> k;
        if(m%2){
            k = n*m/2 - k;
            swap(n, m);
        }
        if(n%2){
            k -= m/2;
            if(k < 0 || k%2){
                cout << "NO\n";
            }
            else{
                cout << "YES\n";
            }
        }
        else{
            if(k%2){
                cout << "NO\n";
            }
            else{
                cout << "YES\n";
            }
        }
    }
    return 0;
}
