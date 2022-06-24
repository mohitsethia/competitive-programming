#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        vector<int> b = a;
        sort(b.begin(), b.end());
        int g = b[0];
        bool bad = false;
        for(int i = 0; i < n; i++){
            if(a[i] != b[i] && a[i]%g != 0){
                bad = true;
                break;
            }
        }
        if(bad) cout << "NO\n";
        else{
            cout << "YES\n";
        }
    }
    return 0;
}
