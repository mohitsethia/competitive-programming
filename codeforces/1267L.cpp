#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int n, l, k;
    cin >> n >> l >> k;
    string s;
    cin >> s;
    vector<int> cnt(26);
    for(char c: s){
        cnt[c-'a']++;
    }
    vector<string> ans(n);
    int L = 0, R = k-1;
    for(int i = 0; i < l; i++){
        int ch = 0;
        for(int j = L; j <= R; j++){
            while(ch < 26 && cnt[ch] == 0){
                ch++;
            }
            cnt[ch]--;
            ans[j].push_back('a'+ch);
        }
        char c = ans[k-1].back();
        while(ans[L].back() != c) L++;
        while(ans[R].back() != c) R--;
    }
    int ch = 0;
    for(int i = 0; i < n; i++){
        while(ans[i].size() < l){
            while(ch < 26 && cnt[ch] == 0) ch++;
            ans[i].push_back('a'+ch);
            cnt[ch]--;
        }
    }
    sort(ans.begin(), ans.end());
    for(string s: ans){
        cout << s << "\n";
    }
    return 0;
}
