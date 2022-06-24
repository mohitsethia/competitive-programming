#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define int long long
int32_t main(){
    int n;
    cin >> n;
    int a[n], b[n], c[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    for(int i = 0; i < n; i++){
        c[i] = b[i] - a[i];
    }
    sort(c, c + n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        auto it = lower_bound(c+i+1, c+n, -c[i]);
        int id = it - c;
        ans += id - (i+1);
    }
    cout << ans << endl;
    return 0;
}
