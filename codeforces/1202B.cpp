#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

const int inf = 1e9;

int32_t main(){
    string s;
    cin >> s;
    vector<vector<int>> dist(10, vector<int>(10, inf));
    for(int x = 0; x < 10; x++){
        for(int y = 0; y < 10; y++){
            dist = vector<vector<int>>(10, vector<int>(10, inf));
            for(int j = 0; j < 10; j++){
                dist[j][(j+x)%10] = 1;
                dist[j][(j+y)%10] = 1;
            }
            for(int k = 0; k < 10; k++){
                for(int i = 0; i < 10; i++){
                    for(int j = 0; j < 10; j++){
                        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                    }
                }
            }
            int ans = 0;
            for(int i = 0; i < (int)s.size(); i++){
                if(i == 0){
                    ans += s[0] == '0' ? 0 : dist[0][s[i]-'0'];
                }
                else{
                    ans += dist[s[i-1]-'0'][s[i]-'0']-1;
                }
            }
            if(ans >= 1e8){
                cout << "-1 ";
            }
            else{
                cout << ans << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
