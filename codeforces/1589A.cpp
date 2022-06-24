#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int u, v;
        cin >> u >> v;
        cout << u*u << " " << -v*v << "\n";
    }
    return 0;
}
