#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
    string change(string word){
        unordered_map<char, int> m;
        for(char c: word){
            if(!m.count(c)){
                m[c] = m.size();
            }
        }
        for(int i = 0; i < (int)word.length(); i++){
            word[i] = 'a' + m[word[i]];
        }
        return word;
    }
public:
    /**
     * @param words: word list
     * @param pattern: pattern string
     * @return: list of matching words
     */
    vector<string> findAndReplacePattern(vector<string> &words, string &pattern) {
        // Write your code here.
        vector<string> res;
        string temp = change(pattern);
        for(int i = 0; i < (int)words.size(); i++){
            if(words[i].size() != pattern.size()) continue;
            if(change(words[i]) == temp) res.push_back(words[i]);
        }
        return res;
    }
};

int main(){
    int n;
    cin >> n;
    vector<string> words(n);
    for(int i = 0; i < n; i++){
        cin >> words[i];
    }
    string pattern;
    cin >> pattern;
    Solution *obj = new Solution();
    vector<string> res = obj->findAndReplacePattern(words, pattern);
    for(auto it: res){
        cout << it << " ";
    }
    return 0;
}
