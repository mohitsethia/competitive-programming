#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

int32_t main(){
    int t;
    cin >> t;
    const string req = "RGB";
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int ans = INT_MAX;
        for(int j = 0; j < 3; j++){ // starting either with R, G or B
            vector<int> res(n);
            int changes = 0;
            for(int i = 0; i < n; i++){
                res[i] = (s[i] != req[(i+j)%3]);
                changes += res[i];
                if(i >= k){
                    changes -= res[i-k];
                }
                if(i >= k-1) ans = min(ans, changes);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
