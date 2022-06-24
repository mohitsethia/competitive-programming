#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int x, r, m;
        cin >> x >> r >> m;
        r *= 60;
        m *= 60;
        int flag = 0;
        if(r > m){
            cout << "NO\n";
            continue;
        }
        if(x < r){
            m -= (r-x);
            x = r;
        }
        if(x >= m || (x >= r && r <= m)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}
