#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int a[2][2];
        bool ok = false;
        for(int k = 0; k < n; k++){
            cin >> a[0][0] >> a[0][1] >> a[1][0] >> a[1][1];
            if(a[0][1] == a[1][0]){
                ok = true;
            }
        }
        ok &= m%2 == 1 ? 0 : 1;
        if(ok){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}
