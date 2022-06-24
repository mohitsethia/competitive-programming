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
        string ans = "";
        for(int i = 0; i < (int)s.length(); i++){
            if(s[i] == 'U'){
                ans += 'D';
            }
            else if(s[i] == 'D'){
                ans += 'U';
            }
            else if(s[i] == 'L'){
                ans += "LR";
                i++;
            }
            else{
                ans += "RL";
                i++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
