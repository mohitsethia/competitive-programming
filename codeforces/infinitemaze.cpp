#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int visited[2000][2000] = {0};
bool canPass(int& n, int& m, vector<vector<char> >& grid, int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m){
        return true;
    }
    if(grid[i][j] == '#'){
        return false;
    }
    for(int k = 0; k < 4; k++){
        if(i+dx[k] < 0 || i+dx[k] >= n || j+dy[k] < 0 || j+dy[k] >= m){
            return true;
        }
        if(grid[i+dx[k]][j+dy[k]] == '.' && canPass(n, m, grid, i+dx[k], j+dy[k]) && !visited[i+dx[k]][j+dy[k]]){
            visited[i+dx[k]][j+dy[k]] = 1;
            return true;
        }
    }
    return false;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char> > grid(n, vector<char>(m));
    int x, y;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'S'){
                x = i, y = j;
            }
        }
    }
    if(canPass(n, m, grid, x, y)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}
