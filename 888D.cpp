#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define int long long

int32_t main(){
    int n, k;
    cin >> n >> k;
    auto choose = [&](int n, int r){
        int ans = 1;
        for(int i = 0; i < r; i++){
            ans *= n-i;
            ans /= (i+1);
        }
        return ans;
    };
    
    int ans = 0;
    int dr[5] = {1, 0, 1, 2, 9};
    for(int i = 0; i <= k; i++){
        ans += choose(n, i)*dr[i];
    }
    cout << ans << "\n";
    return 0;
}
