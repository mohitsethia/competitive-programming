#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define int long long
int power(int base, int exponent, int mod){
    int ans = 1;
    while(exponent > 0){
        if(exponent&1){
            ans *= base;
            ans %= mod;
        }
        base *= base;
        base %= mod;
        exponent /= 2;
    }
    return ans;
}
vector<int> ff, ss;
void divi(string& s, int a, int b){
    int var = 0;
    for(int i = 0; i < s.length(); i++){
        var *= 10;
        var += (s[i]-'0');
        var %= a;
        if(var == 0){
            if(s[i+1] != '0'){
                ff.push_back(i);
            }
        }
    }
    return;
}
int32_t main(){
    string s;
    int a, b;
    cin >> s >> a >> b;
    divi(s, a, b);
    int rem = 0;
    for(int i = s.length()-1; i >= 0; i--){
        int rem_con = power(10, s.length()-i-1, b);
        rem_con *= (s[i]-'0');
        rem_con %= b;
        rem += rem_con;
        rem %= b;
        if(rem == 0){
            ss.push_back(i);
        }
    }
    sort(ss.begin(), ss.end());
    for(int& i: ff){
        if(binary_search(ss.begin(), ss.end(), i+1)){
            cout << "YES" << endl;
            cout << s.substr(0, i+1) << endl;
            cout << s.substr(i+1) << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
