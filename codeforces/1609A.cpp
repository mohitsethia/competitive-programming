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
        int ans = 0;
        int power = 0;
        for(int i = 0; i < n; i++){
            while(a[i]%2 == 0){
                a[i] /= 2;
                power++;
            }
        }
        sort(a.begin(), a.end());
        a[n-1] *= (1ll << power);
        for(int i = 0; i < n; i++){
            ans += a[i];
        }
        cout << ans << "\n";
    }
    return 0;
}
