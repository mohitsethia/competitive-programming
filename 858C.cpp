#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isVowel(char s){
    return s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int i = 0, j = 0;
    int n = s.length();
    int cnt = 0;
    for(int j = 0; j < n; j++){
        if(isVowel(s[j])){
            cnt = 0;           
        }
        else{
            cnt++;
        }
        if(cnt > 2 && (s[j] != s[j-1] || s[j] != s[j-2])){
            cout << " ";
            cnt = 1;
        }
        cout << s[j];
    }
    return 0;
}
