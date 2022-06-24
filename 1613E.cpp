#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<string> s(n);
        pair<int, int> lab = {-1, -1};
        for(int i = 0; i < n; i++){
            cin >> s[i];
            if(lab.first == -1){
                for(int j = 0; j < m; j++){
                    if(s[i][j] == 'L'){
                        lab.first = i;
                        lab.second  = j;
                        break;
                    }
                }
            }
        }
        queue<pair<int, int> > q;
        for(int k = 0; k < 4; k++){
            int i = lab.first + dx[k];
            int j = lab.second + dy[k];
            if(i < 0 || i >= n || j < 0 || j >= m || s[i][j] == '#' || s[i][j] == 'L') continue;
            q.push({i, j});
        }
        while(!q.empty()){
            pair<int, int> temp = q.front();
            q.pop();
            int cnt = 0;
            for(int k = 0; k < 4; k++){
                int i = temp.first + dx[k];
                int j = temp.second + dy[k];
                if(i < 0 || i >= n || j < 0 || j >= m) continue;
                if(s[i][j] == '.'){
                    cnt++;
                }
            }
            if(cnt <= 1){
                s[temp.first][temp.second] = '+';
                for(int k = 0; k < 4; k++){
                    int i = temp.first + dx[k];
                    int j = temp.second + dy[k];
                    if(i < 0 || i >= n || j < 0 || j >= m) continue;
                    if(s[i][j] == '.') q.push({i, j});
                }
            }
        }
        for(int i = 0; i < n; i++){
            cout << s[i] << "\n";
        }
    }
    return 0;
}
