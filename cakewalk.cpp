#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    vector<pair<int, int> > berry;
    for(int i = 0; i < h; i++){
        cin >> s[i];
        for(int j = 0; j < w; j++){
            if(s[i][j] == '*'){
                berry.push_back({i, j});
            }
        }
    }
    // for(auto it: berry){
        // cout << it.first << " " << it.second << "\n";
    // }
    int ans = 0;
    if((int)berry.size() == 0){
        cout << ans << "\n";
        return 0;
    }
    int i = 0, j = 0;
    if(s[0][0] == '*') ans++;
    while(1){
        int k = 0;
        int a = -1;
        int mn = 20;
        for(k = 0; k < (int)berry.size(); k++){
            if(berry[k].first == i && berry[k].second == j) continue;
            if(berry[k].first < i || berry[k].second < j) continue;
            int p = abs(berry[k].first-i);
            int q = abs(berry[k].second-j);
            if(mn > p+q){
                mn = p+q;
                a = k;
            }
            else if(mn == p+q){
                if(berry[a].first > berry[k].first){
                    a = k;
                }
            }
            // cout << k << " " << berry[a].first << " " << berry[a].second << "\n";
        }
        if(mn == 20 || a == -1){
            break;
        }
        else{
            ans++;
            i = berry[a].first;
            j = berry[a].second;
            berry.erase(berry.begin()+a);
        }
        if(i == h && j == w){
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}
