#include<iostream>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int ans = s.size(), cur = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '+'){
                cur++;
            }
            else{
                cur--;
            }
            if(cur < 0){
                ans += (i+1);
                cur = 0;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
