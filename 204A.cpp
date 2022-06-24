#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
using ll = long long;

ll num(ll &n){
    if(n < 10) return n;
    ll last_digit = n%10;
    ll total = n/10 + 9;
    ll first_digit = n;
    while(first_digit >= 10){
        first_digit /= 10;
    }
    if(first_digit > last_digit){
        total--;
    }
    return total;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll l, r;
    cin >> l >> r;
    l--;
    ll total_r = num(r);
    ll total_l  = num(l);
    cout << total_r - total_l << "\n";
    return 0;
}
