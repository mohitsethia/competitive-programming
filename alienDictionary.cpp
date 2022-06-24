#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<queue>

using namespace std;

class Solution{
    public:

    string findOrder(vector<string> &dict){
        if(dict.size() == 0) return "";
        map<char, int> deg;
        map<char, set<char> > graph;
        for(int i = 0; i < (int)dict.size(); i++){
            for(int j = 0; j < (int)dict[i].size(); j++){
                deg[dict[i][j]] = 0;
            }
        }
        for(int i = 1; i < (int)dict.size(); i++){
            string prev = dict[i-1];
            string curr = dict[i];
            int len = min((int)prev.size(), (int)curr.size());
            for(int j = 0; j < len; j++){
                if(curr[j] != prev[j]){
                    if(graph[prev[j]].find(curr[j]) == graph[prev[j]].end()){
                        graph[prev[j]].insert(curr[j]);
                        deg[curr[j]]++;
                    }
                    break;
                }
                if(j == len-1 && curr.size() < prev.size()) return "";
            }
        }

        string ans = "";
        queue<char> q;
        for(auto e: deg){
            if(e.second == 0){
                q.push(e.first);
            }
        }
        while(!q.empty()){
            char temp = q.front();
            q.pop();
            ans += temp;
            if(graph[temp].size()){
                for(auto c: graph[temp]){
                    if(--deg[c] == 0) q.push(c);
                }
            }
        }
        return ans.size() == deg.size() ? ans : "";
    }
};

string order;
bool f(string a, string b){
    int p1 = 0;
    int p2 = 0;
    for(int i = 0; i < min((int)a.size(), (int)b.size()) && p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
    }
    if(p1 == p2 && a.size() != b.size()) return a.size() < b.size();
    return p1 < p2;
}

int main(){
    int n;
    cin >> n;
    vector<string> dict(n);
    for(int i = 0; i < n; i++){
        cin >> dict[i];
    }
    Solution *obj = new Solution();
    string res = obj->findOrder(dict);
    order = res;
    vector<string> temp = dict;
    sort(temp.begin(), temp.end(), f);
    for(int i = 0; i < n; i++){
        if(dict[i] != temp[i]){
            cout << "Either found incorrect order in result or there is no correct ordering from initially given dictionary words\n";
            return 0;
        }
    }
    if(res.size())
        cout << res << "\n";
    else
        cout << "No valid Ordering\n";
    return 0;
}
