#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

int32_t main(){
    int n, m;
    cin >> n >> m;
    if(n > m){
        cout << "0\n";
    }
    else{
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int res = 1;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                res *= abs(a[i]-a[j])%m;
                res %= m;
                if(res == 0) break;
            }
            if(res == 0) break;
        }
        cout << res << "\n";
    }
    return 0;
}
