#include<iostream>
#include<algorithm>
#include<vector>

#define int long long

using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        int res = (n+m-2)*x;
        int d = min(n, m);
        if((n+m-2*d)%2 == 0){
            res = min(res, (d-1)*y + (n+m-2*d)*min(x, y));
        }
        else{
            res = min(res, (d-1)*y + (n+m-2*d-1)*min(x, y) + x);
        }
        cout << res << "\n";
    }
    return 0;
}
