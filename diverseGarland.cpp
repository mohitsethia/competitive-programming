#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    if(n == 1){
        cout << 0 << "\n" << s << endl;
        return 0;
    }
    if(n == 2){
        bool no = true;
        if(s[0] == s[1]){
            no = false;
            cout << "1\n";
            if(s[0] == 'R'){
                s[1] = 'G';
            }
            else if(s[0] == 'B'){
                s[1] = 'R';
            }
            else if(s[0] == 'G'){
                s[1] = 'B';
            }
        }
        if(no) cout << "0\n";
        cout << s << endl;
        return 0;
    }
    for(int i = 1; i < n-1; i++){
        if(s[i] == s[i-1] && s[i] == s[i+1]){
            if(s[i] == 'R'){
                s[i] = 'G';
            }
            else if(s[i] == 'G'){
                s[i] = 'B';
            }
            else{
                s[i] = 'R';
            }
            cnt++;
        }
        else if(i < n-2 && s[i] == s[i+1] && s[i+1] == s[i+2]){
            if(s[i] == 'R'){
                s[i+1] = 'G';
            }
            else if(s[i] == 'G'){
                s[i+1] = 'B';
            }
            else{
                s[i+1] = 'R';
            }
            cnt++;
        }
        else if(s[i] == s[i-1]){
            if(s[i] == 'R'){
                if(s[i+1] == 'G') s[i] = 'B';
                else if(s[i+1] == 'B') s[i] = 'G';
            }
            else if(s[i] == 'G'){
                if(s[i+1] == 'R') s[i] = 'B';
                else if(s[i+1] == 'B') s[i] = 'R';
            }
            else{
                if(s[i+1] == 'R') s[i] = 'G';
                else if(s[i+1] == 'G') s[i] = 'R';
            }
            cnt++;
        }
        else if(s[i] == s[i+1]){
            if(s[i] == 'R'){
                if(s[i-1] == 'G') s[i] = 'B';
                else if(s[i-1] == 'B') s[i] = 'G';
            }
            else if(s[i] == 'G'){
                if(s[i-1] == 'R') s[i] = 'B';
                else if(s[i-1] == 'B') s[i] = 'R';
            }
            else{
                if(s[i-1] == 'R') s[i] = 'G';
                else if(s[i-1] == 'G') s[i] = 'R';
            }
            cnt++;
        }
    }
    cout << cnt << "\n";
    cout << s << "\n";
    return 0;
}
