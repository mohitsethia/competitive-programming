#include<iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.length();
        if(n%2){
            cout << "NO\n";
        }
        else{
            if(s[0] == ')' || s[n-1] == '('){
                cout << "NO\n";
            }
            else{
                cout << "YES\n";
            }
        }
    }
    return 0;
}
