#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define int long long
const int mod = 1e9+9;

int power(int x, int e){
    int res = 1;
    while(e > 0){
        if(e&1){
            res = (res * x)%mod;
        }
        e /= 2;
        x = (x*x)%mod;
    }
    return res%mod;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int mostCorrect = (n%k) + (n/k)*(k-1);
    int ans = 0;
    if(mostCorrect >= m){
        ans = m%mod;
    }
    else{
        int g = power(2, m-mostCorrect + 1)-2;
        if(g < 0){
            g += mod;
        }
        ans = ((g*k)-((m-mostCorrect)*k)+m)%mod;
    }
    cout << ans << endl;
    return 0;
}
