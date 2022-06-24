#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
#define MOD 1000000007
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int sum = 0, x;
    for(int i = 0; i < n; i++){
        cin >> x;
        sum = (sum+x+MOD)%MOD;
    }
    int q, w;
    cin >> q;
    while(q--){
        cin >> w;
        sum = (2*sum)%MOD;
        cout << sum << endl;
    }
    return 0;
}
