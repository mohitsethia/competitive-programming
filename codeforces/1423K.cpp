#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

#define int long long
using namespace std;

const int N = 1e6+1;

bool mark[N];
int cnt[N];

void sieve(){
    for(int i = 2; i*i <= N; i += (i&1)+1){
        if(mark[i] == 0){
            for(int j = i*i; j <= N; j += i){
                mark[j] = 1;
            }
        }
    }
    for(int i = 2; i <= N; i++){
        cnt[i] = cnt[i-1];
        if(mark[i] == 0){
            cnt[i]++;
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sieve();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int sq = sqrt(n);
        int ans = cnt[n]-cnt[sq];
        cout << ans+1 << "\n";
    }
    return 0;
}
