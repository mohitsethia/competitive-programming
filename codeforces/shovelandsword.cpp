#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        cout << min(a, min(b, (a+b)/3)) << "\n";
    }
    return 0;
}
