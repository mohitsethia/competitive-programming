#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>

using namespace std;

#define int long long
#define endl '\n'

void eraseIslands(vector<string>& s, int i, int j, int& n, int& m, int& k){
    if(i < 0 || i >= n || j < 0 || j >= m || s[i][j] == '#' || s[i][j] == '*'){
        return;
    }
    if(k == 0) return;
    s[i][j] = '*';
    k--;
    eraseIslands(s, i+1, j, n, m, k);
    eraseIslands(s, i, j+1, n, m, k);
    eraseIslands(s, i-1, j, n, m, k);
    eraseIslands(s, i, j-1, n, m, k);
    return;
}

int32_t main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    int idx1 = -1, idx2 = -1, cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i][j] == '.'){
                cnt++;
                idx1 = i, idx2 = j;
            }
        }
    }
    k = cnt-k;
    if(idx1 != -1 && idx2 != -1)
        eraseIslands(s, idx1, idx2, n, m, k);
//    for(int i = 0; i < n; i++){
//        for(int j = 0; j < m; j++){
//            if(s[i][j] == '*'){
//                s[i][j] = 'X';
//            }
//        }
//    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i][j] == '.'){
                s[i][j] = 'X';
            }
            if(s[i][j] == '*'){
                s[i][j] = '.';
            }
            cout << s[i][j];
        }
        cout << endl;
    }
    return 0;
}
