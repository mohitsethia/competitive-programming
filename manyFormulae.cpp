#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
const int mod = (int)1e9 + 7;
int main(){
    ll n;
    cin >> n;
    ll sum = 0;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i == 0){
            (sum += n*a[i]) %= mod;
        }
        else{
            (sum += (n-2)*a[i]) %= mod;
        }
    }
    if(n == 1){
        sum = a[0];
    }
    else if(n == 2){
        sum = 2*a[0];
    }
    cout << sum << endl;
    return 0;
}
