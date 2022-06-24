#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<numeric>
#include<iomanip>
#include<cmath>
using namespace std;
using ll = long long;
void solve(){
    ll n;
    cin >> n;
    if(n <= 3){
        cout << "Bob\n";
        return;
    }
    if(n%2){
        cout << "Bob\n";
        return;
    }
    ll cnt = 0;
    while(n%2 == 0){
        cnt++;
        n /= 2;
    }
    if((n == 1 && cnt%2 == 0) || n > 1){
        cout << "Alice\n";
    }
    else{
        cout << "Bob\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
