#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define int long long

int32_t main(){
    int n;
    cin >> n;
    int ans = 0;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        ans += n*y - x;
        a[i] = x-y;
    }
    sort(a.begin()+1, a.end(), greater<int>() );
    for(int i = 1; i <= n; i++){
        ans += i * a[i];
    }
    cout << ans << "\n";
    return 0;
}
