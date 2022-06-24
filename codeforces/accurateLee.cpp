#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        string s;
        cin >> n >> s;
        string res = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '0'){
                res += '0';
            }
            else{
                break;
            }
        }
        string p2 = "";
        bool flag = false;
        bool cool = false;
        for(int i = n-1; i >= 0; i--){
            if(flag && s[i] == '1' && s[i+1] == '0'){
                cool = true;
                break;
            }
            if(!flag && s[i] == '1'){
                p2 += '1';
            }
            else{
                flag = 1;
            }
        }
        if(cool){
            p2 = '0' + p2;
        }
        res += p2;
        cout << res << endl;
    }
    return 0;
}
