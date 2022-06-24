#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int a = 0, b = 0;
    vector<int> ab, ba;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'a') a++;
        else b++;
        if(t[i] == 'a') a++;
        else b++;
        if(s[i] == t[i]) continue;
        else if(s[i] == 'a' && t[i] == 'b') ab.push_back(i+1);
        else ba.push_back(i+1);
    }
    if(a&1){
        cout << "-1\n";
        return 0;
    }
    vector<pair<int, int> > ans;
    n = ab.size();
    if(n%2){
        ans.push_back({ab.back(), ab.back()});
        ans.push_back({ab.back(), ba.back()});
        ab.pop_back();
        ba.pop_back();
    }
    for(int i = 0; i < n-1; i += 2) {
        ans.push_back({ab[i], ab[i+1]});
    }
    n = ba.size();
    for(int i = 0; i < n-1; i += 2) {
        ans.push_back({ba[i], ba[i+1]});
    }
    cout << ans.size() << "\n";
    for(auto e: ans){
        cout << e.first << " " << e.second << "\n";
    }
    return 0;
}
