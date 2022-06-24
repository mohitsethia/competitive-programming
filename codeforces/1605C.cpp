#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        int mn = INT_MAX;
        for(int i = 0; i < n; i++){
            int cnt[3] = {0};
            for(int j = i; j < i+20 && j < n; j++){
                int t = s[j]-'a';
                ++cnt[t];
                if(cnt[0] > cnt[1] && cnt[0] > cnt[2] && j-i >= 1) mn = min(mn, j-i+1);
            }
        }
        if(mn == INT_MAX) mn = -1;
        cout << mn << "\n";
    }
    return 0;
}
