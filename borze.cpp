#include<iostream>
using namespace std;
#define int long long
int32_t main(){
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); ){
        if(s[i] == '.'){
            cout << 0;
            i++;
        }
        else if(s[i] == '-'){
            if(s[i+1] == '.'){
                cout << 1;
            }
            if(s[i+1] == '-'){
                cout << 2;
            }
            i += 2;
        }
    }
    return 0;
}
