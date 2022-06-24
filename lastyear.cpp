#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, ok = 0;
        string s;
        cin >> n >> s;
        if(s[0] == '2' && s[1] == '0' && s[2] == '2' && s[3] == '0'){
            ok = 1;
        }
        else if(s[0] == '2' && s[1] == '0' && s[2] == '2' && s[n-1] == '0'){
            ok = 1;
        }
        else if(s[0] == '2' && s[1] == '0' && s[n-2] == '2' && s[n-1] == '0'){
            ok = 1;
        }
        else if(s[0] == '2' && s[n-3] == '0' && s[n-2] == '2' && s[n-1] == '0'){
            ok = 1;
        }
        else if(s[n-4] == '2' && s[n-3] == '0' && s[n-2] == '2' && s[n-1] == '0'){
            ok = 1;
        }
        if(ok){
            cout << "YES\n";
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
