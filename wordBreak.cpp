#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

class Solution{
    void wordBreakUtil(string s, int n, set<string> &dict, string result, vector<string> &res){
        for(int i = 1; i <= n; i++){
            string pref = s.substr(0, i);
            if(dict.count(pref)){
                if(i == n){
                    result += pref;
                    res.push_back(result);
                    return;
                }
                wordBreakUtil(s.substr(i), n-i, dict, result + pref + " ", res);
            }
        }
    }
    public:
    vector<string> wordBreak(string &s, set<string> &dict){
        vector<string> res;
        wordBreakUtil(s, s.length(), dict, "", res);
        return res;
    }
};

int main(){
    int n;
    cin >> n;
    set<string> st;
    for(int i = 0; i < n; i++){
        string x;
        cin >> x;
        st.insert(x);
    }
    string s;
    cin >> s;
    Solution *obj = new Solution();
    vector<string> res = obj->wordBreak(s, st);
    for(string str: res){
        cout << str << "\n";
    }
    cout << "\n";
    return 0;
}
