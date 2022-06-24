#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

/*
int isSDivisibleByT(string& s, string& t){
    if(s.length()%t.length() > 0){
        return -1;
    }
    string str = "";
    int slen = s.length();
    int tlen = t.length();
    for(int i = 0; i*tlen < slen; i++){
        str += t;
    }
    if(str != s){
        return -1;
    }
    int divisible = 1;
    for(int i = 1; i <= tlen; i++){
        if(tlen%divisible++ != 0){
            continue;
        }
        string sb = "";
        string subStr = t.substr(0,i);
        while(sb.length() < tlen){
            sb += subStr;
        }
        if(sb == t){
            return i;
        }
    }
    return -1;
}
*/

void computeLPSArray(string& str, int M, int lps[]){
    int len = 0;
    int i = 1;
    lps[0] = 0;
    while(i < M){
        if(str[i] == str[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len != 0){
                len = lps[len-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

int isSDivisibleByT(string& s, string& t){
    int slen = s.length();
    int tlen = t.length();
    if(slen%tlen != 0){
        return -1;
    }
    string sb = "";
    for(int i = 0; i*tlen < slen; i++){
        sb += t;
    }
    if(sb != s){
        return -1;
    }
    int lps[tlen];
    memset(lps, 0, sizeof(lps));
    computeLPSArray(t, tlen, lps);
    int len = lps[tlen-1];
    bool isTrue = false;
    if(len > 0 && tlen%(tlen-len) == 0){
        isTrue = true;
    }
    return (isTrue ? len : tlen);
}

int main(){
    string s, t;
    cin >> s >> t;
    int ans = isSDivisibleByT(s, t);
    cout << ans << "\n";
    return 0;
}
