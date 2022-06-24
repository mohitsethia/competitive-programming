#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int ans = 1e18;
        int x;
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n-k; i++){
            int d = a[i+k] - a[i];
            if(ans > (d+1)/2){
                ans = (d+1)/2;
                x = (a[i+k]+a[i])/2;
            }
        }
        cout << x << "\n";
    }
    return 0;
}
