#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        int ans = 0, k = 0, f = 1;
        for(int i = 1; i < n; i++){
            if(s[i] != s[i-1]){
                ans = min(ans+k, f);
                f++;
                k = 0;
            }
            else{
                k++;
            }
        }
        ans = min(ans+k, f);
        ans = (ans + f + 1)/2;
        cout << ans << "\n";
    }
    return 0;
}
