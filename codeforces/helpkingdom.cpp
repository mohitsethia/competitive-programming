#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    string s, t = "";
    cin >> s;
    bool minus = false;
    if(s[0] == '-'){
        minus = true;
    }
    int idx = 0, k;
    for(k = 1; k < s.length(); k++){
        if(s[k] == '.'){
            idx = k;
            break;
        }
        idx = k;
    }
    if(k == s.length()){
        idx = k;
    }
    if(idx + 2 < s.length()){
        t += '.';
        t += s[idx+1];
        t += s[idx+2];
    }
    else if(idx+1 < s.length()){
        t += '.';
        t += s[idx+1];
        t += '0';
    }
    else if(idx == s.length()){
        t += ".00";
    }
    int cnt = 0;
    if(s[idx] == '.' || idx == s.length()){
        idx--;
    }
    for(int i = idx; i >= 0; i--){
        if(s[i] == '-'){
            continue;
        }
        if(cnt == 3){
            t = ',' + t;
            t = s[i] + t;
            cnt = 1;
            continue;
        }
        t = s[i] + t;
        cnt++;
    }
    t = '$' + t;
    if(minus){
        t = '(' + t;
        t += ')';
    }
    cout << t << endl;
    return 0;
}
