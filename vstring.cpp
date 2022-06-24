#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
bool inLine(string &s, int c){
    int cnt = 0;
    int i = 0;
    for(i = 0; i < s.length(); i++){
        if(s[i] == '1'){
            break;
        }
    }
    i++;
    for(; i < s.length(); i++){
        if(s[i] == '0'){
            cnt++;
        }
        else{
            if(cnt > c){
                return false;
            }
        }
    }
    return true;
}
bool reverse(string &s, int c){
    int cnt = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '1'){
            break;
        }
        cnt++;
    }
    for(int i = s.length()-1; i >= 0; i--){
        if(s[i] == '1'){
            break;
        }
        cnt++;
    }
    if(cnt > c){
        return false;
    }
    return true;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, c;
        cin >> n >> c;
        string s;
        cin >> s;
        int count_one = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '1'){
                count_one++;
            }
        }
        if(count_one <= 1){
            cout << "YES\n";
            continue;
        }
        if(!inLine(s, c)){
            if(reverse(s, c)){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
        else{
            cout << "YES\n";
        }
    }
    return 0;
}
