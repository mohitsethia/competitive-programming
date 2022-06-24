#include<iostream>
#include<algorithm>

using namespace std;

#define int long long
string s;

bool check(string t){
    int X = 10;
    for(int i = 0; i < (int)s.length(); i++){
        if(s[i] != t[i]){
            if(s[i] == '_') continue;
            if(s[i] == 'X'){
                if(X != 10){
                    if(t[i]-'0' == X) continue;
                    else return false;
                }
                else{
                    X = t[i] - '0';
                    continue;
                }
            }
            return false;
        }
    }
    return true;
}

int32_t main(){
    cin >> s;
    int possibility = 0;
    for(int i = 0; i <= 100'000'000; i += 25){
        string t = to_string(i);
        if(t.size() == s.size() && check(t)) possibility++;
    }
    cout << possibility << "\n";
    return 0;
}
