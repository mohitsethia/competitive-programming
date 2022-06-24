#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define endl '\n'

using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.length();
        if(n < 3){
            cout << "0\n\n";
            continue;
        }
        vector<int> dp;
        for(int i = 0; i < n-2; i++){
            if(i < n-4 && (s.substr(i, 5) == "twone")){
                    dp.push_back(i+2);
                    i += 3;
            }
            else if(s.substr(i, 3) == "two"){
                dp.push_back(i+1);
                i += 1;
            }
            else if(s.substr(i, 3) == "one"){
                dp.push_back(i+1);
                i += 1;
            }
        }
        cout << (int)dp.size() << endl;
        for(int i = 0; i < (int)dp.size(); i++){
            cout << dp[i]+1 << " ";
        }
        cout << endl;
    }
    return 0;
}
