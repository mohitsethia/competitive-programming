#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

#define int long long
using namespace std;

pair<int, int> findPoint(int x, int y, char ch){
    if(ch == 'U') y++;
    else if(ch == 'D') y--;
    else if(ch == 'R') x++;
    else x--;
    return {x, y};
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int cx = 0, cy = 0;
        bool found = false;
        for(int i = 0; i < (int)s.length(); i++){
            pair<int, int> c = findPoint(cx, cy, s[i]);
            int px = 0, py = 0;
            for(int j = 0; j < (int)s.length(); j++){
                pair<int, int> p = findPoint(px, py, s[j]);
                if(c == p) continue;
                px = p.first;
                py = p.second;
            }
            if(!px && !py){
                found = true;
                cout << c.first << " " << c.second << "\n";
                break;
            }
            cx = c.first;
            cy = c.second;
        }
        if(!found){
            cout << "0 0\n";
        }
    }
    return 0;
}
