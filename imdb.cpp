#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, x, s, r;
        cin >> n >> x;
        int mx = 0;
        for(int i = 0; i < n; i++){
            cin >> s >> r;
            if(s <= x && r > mx){
                mx = r;
            }
        }
        cout << mx << "\n";
    }
    return 0;
}
