#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        cout << '1';
        for(int i = 0; i < a-1; i++){
            cout << '0';
        }
        cout << " ";
        string res = "";
        for(int i = 0; i < c-1; i++){
            res += '0';
        }
        b -= (c-1);
        for(int i = 0; i < b; i++){
            res += '7';
        }
        reverse(res.begin(), res.end());
        cout << res << endl;
    }
    return 0;
}
