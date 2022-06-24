#include<iostream>
#include<algorithm>
#include<numeric>

using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        cout << n*2 << " " << (((n*k)/gcd(n*k, n*k-1))*(n*k-1)) << "\n";
    }
    return 0;
}
