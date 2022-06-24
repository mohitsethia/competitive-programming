#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        if(s.length()%2 != 0){
            cout << "NO" << endl;
            continue;
        }
        if(s[0] == ')' || s[s.length()-1] == '('){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
    return 0;
}

