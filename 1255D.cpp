#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

signed main(){
    int t;
    cin >> t;
    while(t--){
        int R, C, K;
        cin >> R >> C >> K;
        int rice = 0;
        vector<vector<int> > grid(R, vector<int>(C));
        for(int i = 0; i < R; i++){
            string s;
            cin >> s;
            for(int j = 0; j < C; j++){
                grid[i][j] = (s[j] == 'R');
                rice += (s[j] == 'R');
            }
        }
        string chick = "";
        for(int i = 0; i < 26; i++){
            chick += 'a' + i;
        }
        for(int i = 0; i < 26; i++){
            chick += 'A' + i;
        }
        for(int i = 0; i < 10; i++){
            chick += '0' + i;
        }
        int X = rice/K;
        int A = rice - X*K;
        int index = 0;
        int r = 0, c = 0, currRice = 0;
        vector<vector<char> > ans(R, vector<char>(C));
        while(r < R){
            ans[r][c] = chick[index];
            currRice += grid[r][c];
            if(index < A){
                if(currRice == X+1){
                    index++;
                    currRice = 0;
                }
            }
            else{
                if(currRice == X){
                    index++;
                    currRice = 0;
                }
            }
            index = min(index, K-1);
            if(r%2 == 0){
                if(c == C-1){
                    r++;
                }
                else{
                    c++;
                }
            }
            else{
                if(c == 0){
                    r++;
                }
                else{
                    c--;
                }
            }
        }
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                cout << ans[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}
