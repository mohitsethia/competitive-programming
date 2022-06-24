#pragma GCC optimize("O2")
#pragma GCC target("sse4")
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    vector<int> p;
    for(int i = 0; i < (int)s.length(); i++){
        if(s[i] == 'r'){
            p.push_back(i+1);
        }
    }
    for(int i = (int)s.length()-1; i >= 0; i--){
        if(s[i] == 'l'){
            p.push_back(i+1);
        }
    }
    for(int i = 0; i < (int)p.size(); i++){
        cout << p[i] << '\n';
    }
    return 0;
}
