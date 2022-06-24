#include<iostream>
#include<algorithm>

using namespace std;

bool comp(pair<vector<int>, int> const &a, pair<vector<int>, int> const &b){
    return a.first[0] < b.first[0];
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int> > grid(n, vector<int> (m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> grid[i][j];
            }
        }
        vector<pair<vector<int>, int> > rows(n);
        for(int i = 0; i < n; i++) rows[i] = {grid[i], i};
        sort(rows.begin(), rows.end(), comp);
        vector<vector<int> > prefixMax(n, vector<int>(m));
        vector<vector<int> > prefixMin(n, vector<int>(m));
        vector<vector<int> > suffixMax(n, vector<int>(m));
        vector<vector<int> > suffixMin(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int val1 = rows[i].first[j];
                int val2 = i > 0 ? prefixMax[i-1][j] : 0;
                int val3 = j > 0 ? prefixMax[i][j-1] : 0;
                prefixMax[i][j] = max({val1, val2, val3});
            }
        }
        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j < m; j++){
                int val1 = rows[i].first[j];
                int val2 = i+1 < n ? prefixMin[i+1][j] : 1e7;
                int val3 = j > 0 ? prefixMin[i][j-1] : 1e7;
                prefixMin[i][j] = min({val1, val2, val3});
            }
        }
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                int val1 = rows[i].first[j];
                int val2 = i < n-1 ? suffixMax[i+1][j] : 0;
                int val3 = j < m-1 ? suffixMax[i][j+1] : 0;
                suffixMax[i][j] = max({val1, val2, val3});
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = m-1; j >= 0; j--){
                int val1 = rows[i].first[j];
                int val2 = i > 0 ? suffixMin[i-1][j] : 1e7;
                int val3 = j+1 < m ? suffixMin[i][j+1] : 1e7;
                suffixMin[i][j] = min({val1, val2, val3});
            }
        }
        pair<int, int> ans = {-1, -1};
        for(int i = 0; i+1 < n; i++){
            for(int j = 0; j+1 < m; j++){
                pair<int, int> leftUp = {i, j};
                pair<int, int> rightUp = {i, j+1};
                pair<int, int> leftDown = {i+1, j};
                pair<int, int> rightDown = {i+1, j+1};
                if(prefixMax[leftUp.first][leftUp.second] < prefixMin[leftDown.first][leftDown.second] && suffixMax[rightDown.first][rightDown.second] < suffixMin[rightUp.first][rightUp.second]){
                    ans = {i, j};
                    break;
                }
            }
            if(ans.first != -1) break;
        }
        if(ans.first == -1){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
            vector<char> finalAns(n, 'R');
            for(int i = 0; i <= ans.first; i++){
                finalAns[rows[i].second] = 'B';
            }
            string res = "";
            for(auto i :finalAns) res += i;
            res += ' ';
            cout << res << ans.second+1 << "\n";
        }
    }
    return 0;
}
