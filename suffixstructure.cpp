#include<iostream>
#include<vector>
#include<cstring>
#include<stdio.h>
#include<string.h>
using namespace std;
bool arre(string &s, string &t){
    int a[26] = {0}, b[26] = {0};
    for(int i = 0; i < s.length(); i++){
        a[s[i]-'a']++;
    }
    for(int i = 0; i < t.length(); i++){
        b[t[i]-'a']++;
    }
    for(int i = 0; i < 26; i++){
        if(a[i] != b[i]){
            return false;
        }
    }
    return true;
}
bool automaton(string &s, string &t){
    int i = 0, j = 0;
    while(i < s.length() && j < t.length()){
        if(s[i] == t[j]){
            i++;j++;
        }
        else{
            i++;
        }
    }
    if(j == t.length()){
        return true;
    }
    return false;
}
bool both(string &s, string &t){
    int a[26] = {0}, b[26] = {0};
    for(int i = 0; i < s.length(); i++){
        a[s[i]-'a']++;
    }
    for(int j = 0; j < t.length(); j++){
        b[t[j]-'a']++;
    }
    for(int i = 0; i < 26; i++){
        if(a[i] < b[i]){
//            cout << a[i] << " " << b[i];
            return false;
        }
    }
    return true;
}
int main(){
    string s, t;
    cin >> s >> t;
    bool g = arre(s, t);
    bool h = automaton(s, t);
    bool i = both(s, t);
    if(g && !h){
        cout << "array" << endl;
    }
    else if(!g && h){
        cout << "automaton" << endl;
    }
    else if(i){
        cout << "both" << endl;
    }
    else{
        cout << "need tree" << endl;
    }
    return 0;
}
