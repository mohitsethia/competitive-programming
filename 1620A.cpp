#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.length();
        int change = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'N') change++;
        }
        if(change != 1) {
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}
