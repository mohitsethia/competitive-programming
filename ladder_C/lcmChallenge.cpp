#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    if(n == 1 || n == 2){
        cout << n << endl;
    }
    else{
        ll mx = 0;
        if(n%2){
            mx = n*(n-1)*(n-2);
        }
        else{
            if(gcd(n, n-3) == 1){
                mx = n*(n-1)*(n-3);
            }
            else{
                mx = (n-1)*(n-2)*(n-3);
            }
        }
        cout << mx << endl;
    }
    return 0;
}
