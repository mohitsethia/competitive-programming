#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define int long long
const int N = 1e6+5, NN = 1e7+1;
int notPrime[NN+1], dp[NN+1], cnt[NN+1];
void sieve(){
    notPrime[0] = notPrime[1] = 1;
    for(int i = 2; i*i <= NN; i += 1+(i&1)){
        if(!notPrime[i]){
            if(i*1ll * i <= NN){
                for(int j = i*i; j <= NN; j += i){
                    notPrime[j] = 1;
                }
            }
        }
    }
}

void compute(){
    for(int i = 2; i <= NN; i += 1+(i&1)){
        if(!notPrime[i]){
            for(int j = i; j <= NN; j += i){
                dp[i] += cnt[j];
            }
        }
    }
    for(int i = 1; i <= NN; i++){
        dp[i] += dp[i-1];
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sieve();
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    compute();
    int m;
    cin >> m;
    while(m--){
        int l, r;
        cin >> l >> r;
        if(l > NN) cout << "0\n";
        else{
            r = min(r, NN);
            cout << dp[r] - dp[l-1] << endl;
        }
    }
    return 0;
}
