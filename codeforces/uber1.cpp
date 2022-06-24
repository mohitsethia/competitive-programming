#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

vector<string> solve(int n, int d, int p, vector<int> &id, vector<int> &pos, vector<pair<int, int>> &query) {
    map<int, int> IdToPos;
    map<int, set<int>> byValue;
    for(int i = 0; i < id.size(); i++) {
        IdToPos[id[i]] = pos[i];
        byValue[pos[i]].insert(id[i]);
    }
    vector<string> ans(p);
    for(int i = 0; i < p; i++) {
        int x = query[i].first;
        int y = query[i].second;
        bool found = false;
        if(abs(IdToPos[x]-IdToPos[y]) <= d) {
            ans[i] = "Yes";
        } else {
            if(IdToPos[x] > IdToPos[y]) swap(x, y);
            auto it = byValue.find(IdToPos[x]);
            int r = IdToPos[x];
            while(it != byValue.end()) {
                if(it->first - r <= d) {
                    r = it->first;
                    if(it->second.count(y)) {
                        found = true;
                        break;
                    }
                } else {
                    break;
                }
                it++;
            }
            if(!found) {
                ans[i] = "No";
            } else {
                ans[i] = "Yes";
            }
        }
    }
    return ans;
}

int main() {
    int n, d, p;
    cin >> n >> d >> p;
    vector<int> id(n), pos(n);
    for(int i = 0; i < n; i++) {
        cin >> id[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> pos[i];
    }
    vector<pair<int, int>> query(p);
    for(int i = 0; i < p; i++) {
        cin >> query[i].first >> query[i].second;
    }
    vector<string> ans = solve(n ,d, p, id, pos, query);
    for(auto it: ans) {
        cout << it << " ";
    }
    return 0;
}
