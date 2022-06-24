#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        string s, t;
        cin >> s >> t;
        vector<int> cnt(26);
        for(char c: s){
            cnt[c-'a']++;
        }
        vector<int> order(26);
        for(int i = 0; i < 26; i++) order[i] = i;
        if(cnt[0] != 0 && t == "abc") swap(order[1], order[2]);
        string res = "";
        for(auto o: order){
            for(int i = 0; i < cnt[o]; i++){
                res += o+'a';
            }
        }
        cout << res << "\n";
    }
    return 0;
}
