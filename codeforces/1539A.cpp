#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll k;
    cin >> k;
    while(k--){
        ll n, x, t;
        cin >> n >> x >> t;
        if(n == 1){
            cout << "0\n";
        }
        else if(t/x == 0){
            cout << "0\n";
        }
        else{
           ll p = 1ll*t/x;
           n--;
           p = min(p, n);
           ll total_c = p;
           total_c = total_c*total_c;
           total_c -= p;
           total_c /= 2;
           total_c += p*(n+1-p);
           cout << total_c << "\n";
        }
    }
    return 0;
}
