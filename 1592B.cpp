#include<iostream>
#include<algorithm>
#include<vector>

#define int long long

using namespace std;

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        vector<int> a(n), a2(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            a2[i] = a[i];
        }
        sort(a2.begin(), a2.end());
        bool bad = false;
        if(n < 2*x){
            for(int i = n-x; i < x; i++){
                if(a2[i] != a[i]){
                    bad = true;
                    break;
                }
            }
        }
        if(bad){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
    return 0;
}
