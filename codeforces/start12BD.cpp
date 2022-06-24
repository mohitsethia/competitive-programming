#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int res = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                if(i - k >= 0 && s[i-k] == '1') continue;
                if(i + k < n && s[i+k] == '1') continue;
                res++;
            }
        }
        cout << res << "\n";
    }
    return 0;
}
