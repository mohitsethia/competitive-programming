#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        string s;
        cin >> n >> k >> s;
        string goal;
        for(int i = 0; i < k-1; i++){
            goal += "()";
        }
        int p = n-goal.size();
        for(int i = 0; i < p/2; i++){
            goal += "(";
        }
        for(int i = 0; i < p/2; i++){
            goal += ")";
        }
        vector<pair<int, int>> ans;
        for(int i = 0; i < n; i++){
            if(s[i] != goal[i]){
                int j;
                for(j = i+1; j < n; j++){
                    if(s[j] == goal[i]) break;
                }
                reverse(s.begin()+i, s.begin()+j+1);
                ans.push_back({i+1, j+1});
            }
        }
        cout << ans.size() << "\n";
        for(pair<int, int> it: ans){
            cout << it.first << " " << it.second << "\n";
        }
    }
    return 0;
}
