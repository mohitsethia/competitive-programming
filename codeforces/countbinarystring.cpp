#include<iostream>
using namespace std;
#define ll long long int
/*
ll countstr(ll n, ll last_digit){
    if(n == 1){
        return 2;
    }
    int ans = 0;
    if(last_digit == 0){
        ans += countstr(n-1, 0) + countstr(n-1, 1);
    }
    else{
        ans += countstr(n-1, 0);
    }
//    cout << ans << endl;
    return ans;
}
*/
ll a[10000], b[10000];
ll countstr(ll n){
    if(a[n] != -1 && b[n] != -1){   
        return a[n]+b[n];
    }
    for(int i = 2; i <= n; i++){
        a[i] = a[i-1] + b[i-1];
        b[i] = a[i-1];
    }
    return a[n] + b[n];
}
int main(){
    ll t;
    cin >> t;
    memset(a, -1, sizeof a);
    memset(b, -1, sizeof b);
    a[0] = 0;
    a[1] = 1;
    b[0] = 0;
    b[1] = 1;
    while(t--){
        ll n;
        cin >> n;
        cout << countstr(n) << endl;
    }
    return 0;
}
