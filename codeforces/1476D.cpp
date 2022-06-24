#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        int left[n+1];
        left[n] = 0;
        for(int i = (n-1); i >= 0; i--){
            if(s[i] == 'R'){
                left[i] = 1;
                int j = i+1;
                if(j < n){
                    if(s[j] == 'L'){
                        left[i] = 2 + left[i+2];
                    }
                }
            }
            else{
                left[i] = 0;
            }
        }
        int right[n+1];
        right[0] = 0;
        for(int i = 1; i <= n; i++){
            if(s[i-1] == 'L'){
                right[i] = 1;
                int j = i-1;
                if(j > 0){
                    if(s[j-1] == 'R'){
                        right[i] = 2 + right[i-2];
                    }
                }
            }
            else{
                right[i] = 0;
            }
        }
        for(int i = 0; i <= n; i++){
            cout << left[i] + right[i] + 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}
