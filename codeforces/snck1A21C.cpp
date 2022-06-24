#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        cout << max(2*((2*n-k-1)/2), 2*(n-k)) << "\n";
    }
    return 0;
}
