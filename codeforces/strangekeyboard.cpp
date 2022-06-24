#include<iostream>
#include<string>
#include<cstring>
#include<string.h>
using namespace std;
int startpos(string s, string &c, int i){
    string a;
    int j;
    for(j = i; j < s.length() && s[j] != '>'; j++){
        if(s[j] == '*'){
            a.pop_back();
        }
        if(s[j] == '<'){
            return j;
        }
        else{
            a.append(s[j]);
        }
    }
    i = j;
    string b;
    c.copy(b);
    a.append(b);
    a.copy(c);
    return i;
}
int main(){
    string s, a, b, c;
    cin >> s;
    for(int i = 0; i < s.length(); ){
        if(s[i] == '*' && i != 0){
            c.pop_back();
        }
        if(s[i] == '<'){
            int idx = startpos(s, c, i);
            i = idx;
        }
        else{
            if(s[i] == '>'){
                continue;
            }
            c.append(s[i]);
        }
    }
    cout << c << endl;
    return 0;
}
