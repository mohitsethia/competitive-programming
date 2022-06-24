#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int32_t main(){
    int a[3];
    for(int i = 0; i < 3; i++) cin >> a[i];
    int k;
    cin >> k;
    sort(a, a+3);
    int ans = 1;
    for(int i = 0; i < 3; i++){
        int c = min(a[i]-1, k/(3-i));
        ans *= c+1;
        k -= c;
    }
    cout << ans << "\n";
    return 0;
}
