#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int ans = 0;
        string s;
        cin >> s;
        for(int i = 0; i < s.length(); i++){
            if((s[i] == 'x' && s[i+1] == 'y') || (s[i] == 'y' && s[i+1] == 'x')){
                ans++;
                i++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
