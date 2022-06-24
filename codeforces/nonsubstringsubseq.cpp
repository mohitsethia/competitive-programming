#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        string s;
        cin >> n >> q >> s;
        while(q--){
            int l, r;
            cin >> l >> r;
            bool flag = true;
            l--; r--;
            for(int i = 0; i < l and flag; i++){
                if(s[i] == s[l]){
                    flag = false;
                }
            }
            for(int i = r+1; i < n and flag; i++){
                if(s[i] == s[r]){
                    flag = false;
                }
            }
            cout << (flag? "NO" : "YES") << endl;
        }
    }
    return 0;
}
