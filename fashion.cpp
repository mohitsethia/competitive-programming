#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long int
int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll m[n], f[n], sum = 0;
        for(ll i = 0; i < n; i++){
            cin >> m[i];
        }
        for(ll i = 0; i < n; i++){
            cin >> f[i];
        }
        sort(m, m+n);
        sort(f, f+n);
        for(ll i = 0; i < n; i++){
            sum += (m[i]*f[i]);
        }
        cout << sum << endl;
    }
    return 0;
}
