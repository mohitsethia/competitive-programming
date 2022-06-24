#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        vector<string> s(9);
        for(int i = 0; i < 9; i++){
            cin >> s[i];
            for(int j = 0; j < 9; j++){
                s[i][j] = (s[i][j] == '5' ? '7' : s[i][j]);
            }
        }
        for(int i = 0; i < 9; i++){
            cout << s[i] << "\n";
        }
    }
    return 0;
}
