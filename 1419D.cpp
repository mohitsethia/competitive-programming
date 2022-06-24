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
    vector<int> b(n);
    int id = 1;
    for(int i = 0; i < n/2; i++){
        b[id] = a[i];
        id += 2;
    }
    id = 0;
    for(int i = n/2; i < n; i++){
        b[id] = a[i];
        id += 2;
    }
    int ans = 0;
    for(int i = 1; i < n-1; i += 2){
        ans += b[i] < min(b[i-1], b[i+1]);
    }
    cout << ans << "\n";
    for(int i = 0; i < n; i++){
        cout << b[i] << " \n"[i == n-1];
    }
    return 0;
}
