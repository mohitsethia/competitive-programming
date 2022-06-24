#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

#define int long long 

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.length();
        int row = 0;
        int i = 0, j = 0;
        for(i = 0; i < n; i++){
            if(s[i] >= '0' && s[i] <= '9') break;
            row = row*26 + (s[i] - 'A' + 1);
        }
        bool RC = false;
        string str = "";
        for(j = i; j < n; j++){
            if(s[j] == 'C'){
                RC = true;
                break;
            }
            str += s[j];
        }
        string ans = "";
        if(RC){
            int col = 0;
            for(int k = j+1; k < n; k++){
                col = col*10 + (s[k] -'0');
            }
            while(col){
                col--;
                int to = (col%26);
                char temp = to + 'A';
                ans = temp + ans;
                col /= 26;
            }
            ans += str;
        }
        else{
            ans += 'R';
            ans += str;
            ans += 'C';
            string temp = "";
            string to = "";
            while(row){
                temp = ((row % 10) + '0');
                to = temp + to;
                row /= 10;
            }
            ans += to;
        }
        cout << ans << "\n";
    }
    return 0;
}
