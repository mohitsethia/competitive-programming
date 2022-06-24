#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            a[i]--;
        }
        vector<int> c(m);
        for(int i = 0; i < m; i++){
            cin >> c[i];
        }
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        int cnt = 0;
        int res = 0;
        for(int i = 0; i < n; i++){
            if(cnt <= a[i]){
                res += c[cnt++];
            }
            else{
                res += c[a[i]];
            }
        }
        cout << res << "\n";
    }
    return 0;
}
