#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

const int MOD = 1e9+7;

int32_t main(){
    int n, m;
    cin >> n >> m;
    int N = max(n, m)+5;
    vector<int> f = {1,1};
    for(int i = 0; i < N; i++){
        f.push_back((f[f.size()-1]+f[f.size()-2]) % MOD);
    }
    cout << 2*((f[n]+f[m]-1)+MOD)%MOD << "\n";
    return 0;
}
