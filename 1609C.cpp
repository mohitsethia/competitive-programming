#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

const int N = 1e6;

vector<bool> is_prime(N+1, true);

void sieve(){
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i*i <= N; i += (i&1)+1){
        if(is_prime[i]){
            for(int j = i*i; j <= N; j += i){
                is_prime[j] = false;
            }
        }
    }
}

void solve(){
    int n, e;
    cin >> n >> e;
    vector<int> a(n);
    vector<int> ones(n), primes[e+1];
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x == 1){
            ones[i] = 1;
        }
        else if(is_prime[x]){
            primes[i%e].push_back(i);
        }
    }
    vector<int> dp1(n), dp2(n);
    for(int i = 0; i < n; i++){
        if(i-e >= 0 && ones[i] == 1) dp1[i] = dp1[i-e]+1;
        else if(ones[i] == 1)
            dp1[i] += ones[i];
    }
    for(int i = n-1; i >= 0; i--){
        if(i+e < n && ones[i] == 1) dp2[i] = dp2[i+e]+1;
        else if(ones[i] == 1)
            dp2[i] += ones[i];
    }
    int ans = 0;
    for(int i = 0; i <= e; i++){
        if(primes[i].size()){
            for(auto it: primes[i]){
                int left = it-e >= 0 ? dp1[it-e] : 0;
                int right = it+e < n ? dp2[it+e] : 0;
                int sum = left*right;
                sum += left + right;
                ans += sum;
            }
        }
    }
    cout << ans << "\n";
}

int32_t main(){
    sieve();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
