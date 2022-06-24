#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

int32_t main(){
    int n, m;
    cin >> n >> m;
    vector<int> fact(n+1);
    fact[0] = fact[1] = 1;
    for(int i = 1; i <= n; i++){
        (fact[i] = i*fact[i-1] % m);
    }
    int res = 0;
    for(int i = 1; i <= n; i++){
        res += (n-i+1) * (fact[i] * fact[n-i+1] % m);
        res %= m;
    }
    cout << res << "\n";
    return 0;
}
