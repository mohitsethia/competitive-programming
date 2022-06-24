#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<char> > s(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> s[i][j];
        }
    }
    vector<int> letter(n, 1000000), number(n, 1000000), special(n, 1000000);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int mn = min(j, m-j);
            if(s[i][j] >= 'a' && s[i][j] <= 'z'){
                letter[i] = min(letter[i], mn);
            }
            if(s[i][j] >= '0' && s[i][j] <= '9'){
                number[i] = min(number[i], mn);
            }
            if(s[i][j] == '*' || s[i][j] == '#' || s[i][j] == '&'){
                special[i] = min(special[i], mn);
            }
        }
    }
    int ans = 1000000;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(j == k || i == k || i == j) continue;
                ans = min(ans, letter[i]+number[j]+special[k]);
                if(ans == 0){
                    cout << ans << endl;
                    return 0;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
