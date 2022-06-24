#include<iostream>
#include<algorithm>
#include<set>
#include<climits>
#include<cstring>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int c = 0;
        for(int i = 1; i < s.length(); i++){
            bool change = false;
            if(s[i] == s[i-1] && s[i-1] != '.'){
                change = true;
            }
            if(i >= 2 && s[i] == s[i-2] && s[i-2] != '.'){
                change = true;
            }
            s[i] = change ? '.' : s[i];
            c += change;
        }
        cout << c << "\n";
    }
    return 0;
}
