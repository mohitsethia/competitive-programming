#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, w, r;
        cin >> n >> w >> r;
        int total = 0, a[n];
        map<int, int> mp;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            total += a[i];
            mp[a[i]]++;
        }
        if(r >= w){
            cout << "YES" << endl;
            continue;
        }
        w -= r;
        for(int i = 0; i < n; i++){
            int c = mp[a[i]];
            if(c >= 2){

                if(c%2){
                    w -= (c-1)*a[i];
                }
                else{
                    w -= c*a[i];
                }
                mp[a[i]] -= c;
            }
            if(w <= 0) break;
        }
        if(w <= 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
