#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    string s, res = "";
    cin >> s;
    char ch = 'a';
    for(int i = s.length()-1; i >= 0; i--){
        if(s[i] > ch){
            ch = s[i];
            res += ch;
        }
        else if(s[i] == ch){
            res += ch;
        }
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
    return 0;
}
