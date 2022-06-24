#include<iostream>
#include<algorithm>

using namespace std;

bool isPalindrome(string t){
    int n = t.length();
    for(int i = 0; i <= n/2; i++){
        if(t[i] != t[n-i-1]){
            return false;
        }
    }
    return true;
}

int main(){
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 0; i < (int)s.length(); i++){
        cnt += s[i] == s[0];
    }
    if(cnt == (int)s.length() || cnt == (int)s.length()-1){
        cout << "Impossible\n";
    }
    else{
        string t = s;
        for(int i = 0; i < (int)s.length(); i++){
            t = t.back() + t;
            t.pop_back();
            if(s != t && isPalindrome(t)){
                cout << "1\n";
                return 0;
            }
        }
        cout << "2\n";
    }
    return 0;
}
