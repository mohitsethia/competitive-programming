#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
bool checkPalin(string& s){
    int n = s.length();
    for(int i = 0; i < n/2; i++){
        if(s[i] != s[n-i-1]){
            return false;
        }
    }
    return true;
}
void no(){
    cout << "-1" << endl;
    return;
}
void solve(int& a, int& b, string& s){
    for(int times = 0; times < 2; times++){
        for(int i = 0; i < s.size(); i++){
            int j = s.size()-i-1;
            if(s[i] != '?'){
                if(s[j] == '?') s[j] = s[i];
                else if(s[i] != s[j]){
                    no();
                    return;
                }
            }
        }
        reverse(s.begin(), s.end());
    }
    a -= count(s.begin(), s.end(), '0');
    b -= count(s.begin(), s.end(), '1');
    int ques = count(s.begin(), s.end(), '?');
    bool emptyMid = (s.size()%2 == 1 && s[s.size()/2] == '?');
    if(a < 0 || b < 0 || a+b != ques || (emptyMid && a%2 == 0 && b%2 == 0)){
        no();
        return;
    }
    if(a%2 == 1 || b%2 == 1){
        int i = s.size()/2;
        if(s[i] != '?'){
            no();
            return;
        }
        s[i] = (a%2 == 1 ? '0' : '1');
        if(a%2) a--;
        else if(b%2) b--;
    }
    if(a%2 || b%2){
        no();
        return;
    }
    for(int i = 0; i < s.size(); i++){
        int j = s.size()-i-1;
        if(s[i] == '?'){
            if(a > 0){
                s[i] = s[j] = '0';
                a -= 2;
            }
            else{
                s[i] = s[j] = '1';
                b -= 2;
            }
        }
    }
    cout << s << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int a, b;
        string s;
        cin >> a >> b >> s;
        if(s.length() == 1){
            if(s[0] != '?'){
                if((s[0] == '0' && a) || (s[0] == '1' && b)){
                    cout << s << endl;
                }
                else{
                    cout << "-1\n";
                }
            }
            else{
                if(a){
                    cout << "0\n";
                }
                else{
                    cout << "1\n";
                }
            }
            continue;
        }
        solve(a, b, s);
    }
    return 0;
}
