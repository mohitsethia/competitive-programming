#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        if(s.length() < 10){
            cout << "NO" << endl;
            continue;
        }
        map<char, int> mp;
        for(int i = 1; i < s.length() - 1; i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                mp['L']++;
            }
            else if(s[i] >= 'A' && s[i] <= 'Z'){
                mp['U']++;
            }
            else if(s[i] >= '0' && s[i] <= '9'){
                mp['N']++;
            }
            else if(s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '&' || s[i] == '?'){
                mp['S']++;
            }
            else{
                mp['O']++;
            }
        }
        int flag = 0;
        if(mp.count('U') && mp.count('N') && mp.count('S')){
            if(!mp.count('L')){
                if((s[0] >= 'a' && s[0] <= 'z') || (s[s.length()-1] >= 'a' && s[s.length()-1] <= 'z')){
                    mp['L']++;
                    mp['L']++;
                }
                if(mp.count('L')){
                    flag = 1;
                }
            }
            else{
                flag = 1;
            }
        }
        if(mp.count('O')){
            flag = 0;
        }
        if(flag){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
