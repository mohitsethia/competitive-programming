#include<iostream>

using namespace std;

bool isVowel(char &s){
    return s == 'a' || s == 'o' || s == 'y' || s == 'e' || s == 'u' || s == 'i';
}

int main(){
    string s;
    cin >> s;
    string res = "";
    for(int i = 0; i < (int)s.length(); i++){
        if(s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i]-'A' + 'a';
        if(isVowel(s[i])) continue;
        res += '.';
            res += s[i];
    }
    cout << res << "\n";
    return 0;
}
