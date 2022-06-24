#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<unordered_map>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int> > a(n, vector<int>(n+1)), vis(n+1, vector<int>(n+1, 0));
    vector<int> rem(n+1);
    unordered_map<int, pair<int, int> > mp;
    set<int> s;
    for(int i = 0; i < n; i++){
        cin >> a[i][i];
        rem[i+1] = i;
        mp[i] = {i, i};
        s.insert(i);
        vis[i][i] = 1;
    }
    while(!s.empty()){
        vector<int> temp;
        for(auto it: s){
            int x = mp[it].first;
            int y = mp[it].second;
            if(rem[a[x][y]] == 0){
                temp.push_back(it);
                continue;
            }
            int total = 0;
            if(x-1 >= 0 && x-1 >= y && !vis[x-1][y]) total++;
            if(x+1 < n && x+1 >= y && !vis[x+1][y]) total++;
            if(y-1 >= 0 && y-1 <= x && !vis[x][y-1]) total++;
            if(y+1 < n && y+1 <= y && !vis[x][y+1]) total++;
            if(total == 1){
                if(x-1 >= 0 && x-1 >= y && !vis[x-1][y]) mp[it] = {x-1, y};
                if(x+1 < n && x+1 >= y && !vis[x+1][y]) mp[it] = {x+1, y};
                if(y-1 >= 0 && y-1 <= x && !vis[x][y-1]) mp[it] = {x, y-1};
                if(y+1 < n && y+1 <= y && !vis[x][y+1]) mp[it] = {x, y+1};
                rem[a[it][it]]--;
                x = mp[it].first;
                y = mp[it].second;
                vis[x][y] = 1;
                a[x][y] = a[it][it];
            }
        }
        for(auto i: temp){
            s.erase(i);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}



/*
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    scanf("%lld", &n);
//    cin >> n;
    vector<vector<int> > a(n, vector<int>(n, 0)), vis(n, vector<int>(n, 0));
    set<int> s;
    unordered_map<int, pair<int, int> > mp;
    vector<int> rem(n+1);
    for(int i = 0; i < n; i++){
        scanf("%lld", &a[i][i]);
//        cin >> a[i][i];
        rem[i+1] = i;
        s.insert(i);
        mp[i] = {i, i};
        vis[i][i] = 1;
    }   
    while(!s.empty()){
        vector<int> temp;
        for(auto i: s){
            int tot = 0;
            int x = mp[i].first;
            int y = mp[i].second;
            if(rem[a[x][y]] == 0){
                temp.push_back(i);
                continue;
            }
            if(x-1 >= 0 && x-1 >= y && !vis[x-1][y]) tot++;
            if(x+1 < n && x+1 >= y && !vis[x+1][y]) tot++;
            if(y-1 >= 0 && y-1 <= x && !vis[x][y-1]) tot++;
            if(y+1 < n && y+1 <= y && !vis[x][y+1]) tot++;
            if(tot == 1){
                if(x-1 >= 0 && x-1 >= y && !vis[x-1][y]) mp[i] = {x-1, y};
                if(x+1 < n && x+1 >= y && !vis[x+1][y]) mp[i] = {x+1, y};
                if(y-1 >= 0 && y-1 <= x && !vis[x][y-1]) mp[i] = {x, y-1};
                if(y+1 < n && y+1 <= y && !vis[x][y+1]) mp[i] = {x, y+1};
                x = mp[i].first;
                y = mp[i].second;
                rem[a[i][i]]--;
                vis[x][y] = 1;
                a[x][y] = a[i][i];
            }
        }
        for(auto it: temp) s.erase(it);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            printf("%lld ", a[i][j]);
//            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
*/
