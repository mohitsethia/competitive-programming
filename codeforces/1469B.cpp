#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(i) a[i] += a[i-1];
        }
        int m;
        cin >> m;
        vector<int> b(m);
        for(int i = 0; i < m; i++){
            cin >> b[i];
            if(i) b[i] += b[i-1];
        }
        int ans = 0;
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                int res = 0;
                if(i) res += a[i-1];
                if(j) res += b[j-1];
                ans = max(ans, res);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
