/*
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
void dfs(vector<vector<char> >& grid, int& n, int& m, int i, int j, char color){
    if(i < 0 || j < 0 || i == n || j == m || grid[i][j] != '.') return;
    if(color == 'R'){
        color = 'W';
    }
    else{
        color = 'R';
    }
    grid[i][j] = color;
    dfs(grid, n, m, i-1, j, color);
    dfs(grid, n, m, i, j-1, color);
    dfs(grid, n, m, i+1, j, color);
    dfs(grid, n, m, i, j+1, color);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<char> > grid(n, vector<char>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> grid[i][j];
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] != '.'){
                    if(i-1 >= 0 && grid[i-1][j] == '.')
                        dfs(grid, n, m, i-1, j, grid[i][j]);
                    if(j-1 >= 0 && grid[i][j-1] == '.')
                        dfs(grid, n, m, i, j-1, grid[i][j]);
                    if(i+1 < n && grid[i+1][j] == '.')
                        dfs(grid, n, m, i+1, j, grid[i][j]);
                    if(j+1 < n && grid[i][j+1] == '.')
                        dfs(grid, n, m, i, j+1, grid[i][j]);
                }
            }
        }
        bool both = false, colored = false, empty = false, adjacent = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '.'){
                    empty = true;
                }
                else{
                    colored = true;
                }
                both = empty & colored;
                if(i+1 < n && grid[i+1][j] == grid[i][j] && grid[i][j] != '.'){
                    adjacent = true;
                }
                if(j+1 < m &&  grid[i][j+1] == grid[i][j] && grid[i][j] != '.'){
                    adjacent = true;
                }
            }
        }
        if(adjacent || both) cout << "NO\n";
        else{
            if(empty && !colored){
                char color = 'R';
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < m; j++){
                        grid[i][j] = color;
                        color = color == 'R' ? 'W' : 'R';
                    }
                    if(i == 0){
                        color = grid[i][0] == 'R' ? 'W' : 'R';
                    }
                    else{
                        color = grid[i-1][0] == 'R' ? 'W' : 'R';
                    }
                }
            }
            cout << "YES\n";
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    cout << grid[i][j];
                }
                cout << '\n';
            }
        }
    }
    return 0;
}
*/























#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
void solve(vector<vector<char> >& grid, int& n, int& m){
    vector<string> R, W;
    string s1 = "", s2 = "";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i%2 == 0){
                s1 += "RW";
                s2 += "WR";
            }
            else{
                s1 += "WR";
                s2 += "RW";
            }
        }
        R.push_back(s1);
        s1 = "";
        W.push_back(s2);
        s2 = "";
    }
    bool one = false, two = false;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] != R[i][j] && grid[i][j] != '.') one = true;
            if(grid[i][j] != W[i][j] && grid[i][j] != '.') two = true;
        }
    }
    if(one && two){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    if(one && !two){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << W[i][j];
            }
            cout << endl;
        }
    }
    else if((!one && two) || (!one && !two)){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << R[i][j];
            }
            cout << endl;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<char> > grid(n, vector<char>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> grid[i][j];
            }
        }
        solve(grid, n, m);
    }
    return 0;
}
