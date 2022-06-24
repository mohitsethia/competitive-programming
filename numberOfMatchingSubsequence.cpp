#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int cnt = 0;
        vector<pair<string, int>> w[26];
        for(const string &str: words){
            w[str[0]-'a'].push_back({str, 1});
        }
        for(const char &c: s){
            if(w[c-'a'].size() == 0) continue;
            vector<pair<string, int>> advance = w[c-'a'];
            w[c-'a'].clear();
            for(pair<string, int> it: advance){
                if(it.second == it.first.size()){
                    cnt++;
                    continue;
                }
                w[it.first[it.second++]-'a'].push_back({it.first, it.second});
            }
        }
        return cnt;
    }
};

int32_t main(){
    Solution *obj = new Solution();
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n;
        cin >> n;
        vector<string> words(n);
        for(int i = 0; i < n; i++) cin >> words[i];
        cout << obj->numMatchingSubseq(s, words) << "\n";
    }
    return 0;
}
