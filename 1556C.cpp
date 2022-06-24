#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

signed main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 0; i +1 < n; i += 2){
        ans += min(a[i], a[i+1]);
        int c[2] = {a[i], a[i+1]};
        int mn = c[0]-c[1];
        for(int j = i+3; j < n; j += 2){
            if(mn < 0) break;
            c[0] += a[j-1];
            c[1] += a[j];
            int start = a[i], end = a[j];
            start -= max(0ll, c[0]-c[1]);
            int temp = mn - max(0ll, c[0]-c[1]);
            end -= max(0ll, c[1]-c[0]);
            int curr = min(start, min(end, temp+1));
            ans += max(0ll, curr);
            mn = min(mn, c[0]- c[1]);
        }
    }
    cout << ans << "\n";
    return 0;
}
