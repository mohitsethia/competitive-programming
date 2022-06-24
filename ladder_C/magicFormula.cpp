#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define int long long
const int MAXN = (int)1e6+10;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a[MAXN];
    a[0] = 0;
    for(int i = 1; i < MAXN; i++){
        a[i] = a[i-1]^i;
    }
    cout << endl;
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1 ; i <= n; i++){
        int x;
        cin >> x;
        ans ^= x;
        if((n/i)%2){
            ans ^= a[i-1];
        }
        ans ^= a[n%i];
    }
    cout << ans << endl;
    return 0;
}
