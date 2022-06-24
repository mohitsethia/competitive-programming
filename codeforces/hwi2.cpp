#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;

#define int long long
#define mod 1000000007

int32_t main(){
    string a;
    cin >> a;
    vector<int> f(10);
    for(int  i = 1; i < 10; i++){
        cin >> f[i];
    }
    int num = 0;
    for(int i = 0; i < a.length(); i++){
        int c = a[i]-'0';
        if(c < f[c]){
            a[i] = (f[c]+'0');
        }
        num = num*10 + (a[i]-'0');
    }
    num %= mod;
    cout << num << endl;
    return 0;
}
