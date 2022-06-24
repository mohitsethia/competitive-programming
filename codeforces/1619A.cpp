#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        if(s.length()%2){
            cout << "NO\n";
        }
        else{
            int n = s.length()/2;
            string a = s.substr(0, n);
            string b = s.substr(n);
            if(a == b){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }
    return 0;
}
