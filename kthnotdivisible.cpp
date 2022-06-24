#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
#define ll long long int
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        ll x = (k-1)/(n-1);
        cout << k+x << endl;
    }
    return 0;
}
