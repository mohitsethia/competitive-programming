#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

int32_t main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int j = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        while(j < n && a[j]-a[i] <= 5){
            j++;
            ans = max(ans, j-i);
        }
    }
    cout << ans << "\n";
    return 0;
}
