#include<iostream>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int open = 0, close = 0, count = 0;
        string s;
        cin >> s;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                open++;
            }
            else{
                close++;
            }
            if(close > open){
                close = open;
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}
