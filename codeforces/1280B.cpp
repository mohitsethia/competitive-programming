#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int r, c;
        cin >> r >> c;
        vector<string> grid(r);
        vector<int> rows(r), cols(c);
        int total = 0;
        char ch;
        bool ok = false;
        for(int i = 0; i < r; i++){
            cin >> grid[i];
            for(int j = 0; j < c; j++){
                ch = grid[i][j];
                if(ch == 'A'){
                    if((i == 0 && j == 0) || (i == r-1 && j == c-1) || (i == 0 && j == c-1) || (i == r-1 && j == 0)){
                        ok = true;
                    }
                    rows[i]++;
                    cols[j]++;
                    total++;
                }
            }
        }
        if(total == 0){
            cout << "MORTAL\n";
            continue;
        }
        else if(total == r*c){
            cout << "0\n";
            continue;
        }
        if(rows[0] == c || rows[r-1] == c || cols[0] == r || cols[c-1] == r){
            cout << "1\n";
            continue;
        }
        if(ok){
            cout << "2\n";
            continue;
        }
        int mx = *max_element(rows.begin(), rows.end());
        if(mx == c){
            cout << "2\n";
            continue;
        }
        mx = *max_element(cols.begin(), cols.end());
        if(mx == r){
            cout << "2\n";
            continue;
        }
        if(rows[r-1] || rows[0] || cols[c-1] || cols[0]){
            cout << "3\n";
            continue;
        }
        cout << "4\n";
    }
    return 0;
}
