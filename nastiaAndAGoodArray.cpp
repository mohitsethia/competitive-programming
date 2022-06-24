#include<iostream>
#include<algorithm>
#include<cstdio>
#define int long long
#define ct 1000000007
using namespace std;
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        if(n == 1){
            cout << 0 << endl;
            continue;
        }
        cout << (n+1)/2 << endl;
        for(int i = 0; i < n; i += 2){
            if(i == n-1){
                continue;
            }
            cout << i+1 << " " << i+2 << " " << ct << " " << min(a[i], a[i+1]) << endl;
            a[i+1] = min(a[i], a[i+1]);
        }
        if(n&1){
            cout << n-1 << " " << n << " " << min(a[n-1], a[n-2]) << " " << ct << endl;
        }
    }
    return 0;
}
