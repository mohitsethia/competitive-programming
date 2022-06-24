#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<numeric>
using namespace std;
const int n = 32000;
vector<int> primes, vis(n+1);
int factorize(int n){
    int cnt = 0;
    for(auto x: primes){
        if(n < x) break;
        while(n%x == 0){
            n /= x;
            cnt++;
        }
    }
    if(n > 1) cnt++;
    return cnt;
}
void sieve(){
    for(int i = 2; i*i <= n; i += (i&1) + 1){
        if(!vis[i]){
            for(int j = i*i; j <= n; j += i){
                vis[j] = 1;
            }
        }
    }
    for(int i = 2; i <= n; i += (i&1) +1){
        if(!vis[i]) primes.emplace_back(i);
    }
}
void solve(){
    int a, b, k;
    cin >> a >> b >> k;
    if(k > 60){
        cout << "NO\n";
    }
    else{
        int minOperations = 0;
        if(a == b){
            minOperations = 2;
        }
        else{
            if(a%b == 0 || b%a == 0){
                minOperations = 1;
            }
            else{
                minOperations = 2;
            }
        }
        int maxOperations = 0;
        int g = gcd(a, b);
        a /= g;
        b /= g;
        int x = factorize(a);
        int y = factorize(b);
        int z = factorize(g);
        maxOperations = x + y + 2*z;
        if(k >= minOperations && k <= maxOperations) cout << "YES\n";
        else cout << "NO\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sieve();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
