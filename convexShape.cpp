#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int> > pre(n+1, vector<int>(m+1, 0)), suf(n+1, vector<int>(m+1, 0));
    vector<pair<int, int> > p;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char c;
            cin >> c;
            if(c == 'B'){
                pre[i][j] = 1;
                p.push_back({i, j});
                suf[i][j] = 1;
            }
            pre[i][j] += pre[i][j-1];
        }
    }
    for(int j = 1; j <= m; j++){
        for(int i = 1; i <= n; i++){
            suf[i][j] += suf[i-1][j];
        }
    }
    bool flag = true;
    for(int i = 0; i < (int)p.size(); i++){
        for(int j = i+1; j < (int)p.size(); j++){
            int r1 = p[i].first;
            int c1 = p[i].second;
            int r2 = p[j].first;
            int c2 = p[j].second;
            if(suf[max(r1, r2)][c1]-suf[min(r1, r2)-1][c1] == abs(r1-r2)+1 && pre[r2][max(c1, c2)]-pre[r2][min(c1, c2)-1] == abs(c1-c2)+1){
                continue;
            }
            if(suf[max(r1, r2)][c2]-suf[min(r1, r2)-1][c2] == abs(r1-r2)+1 && pre[r1][max(c1, c2)]-pre[r1][min(c1, c2)-1] == abs(c1-c2)+1){
                continue;
            }
            flag = false;
            i = (int)p.size();
            break;
        }
    }
    if(flag){
        puts("YES");
    }
    else{
        puts("NO");
    }
    return 0;
}























/*
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
#define int long long
int row[100][100];
int col[100][100];
int32_t main(){
    int n, m;
    cin >> n >> m;
    char ar[100][100];
    vector<pair<int, int>> sp;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> ar[i][j];
            row[i][j] = row[i][j-1];
            if(ar[i][j] == 'B'){
                sp.push_back({i, j});
                row[i][j]++;
            }
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            col[j][i] = col[j-1][i];
            if(ar[j][i] == 'B'){
                col[j][i]++;
            }
        }
    }
    bool flag = true;
    for(int i = 0; i < (int)sp.size(); i++){
        for(int j = i+1; j < (int)sp.size(); j++){
            int r1, c1, r2, c2;
            r1 = sp[i].first;
            c1 = sp[i].second;
            r2 = sp[j].first;
            c2 = sp[j].second;
            if(row[r1][max(c1, c2)] - row[r1][min(c1, c2) - 1] == abs(c2-c1)+1 && col[max(r1, r2)][c2] - col[min(r1, r2)-1][c2] == abs(r2-r1)+1){
                continue;
            }
            if(col[max(r1, r2)][c1] - col[min(r1, r2)-1][c1] == abs(r2-r1)+1 && row[r2][max(c1, c2)] - row[r2][min(c1, c2)-1] == abs(c1-c2)+1){
                continue;
            }
            flag = false;
            break;
        }
        if(!flag) break;
    }
    if(flag) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
*/
