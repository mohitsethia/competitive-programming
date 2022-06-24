#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<int> v;
        for(int j = 0; j < min(n, m); j++){
            for(int i = 0; i < n; i++){
                if(i == 0){
                    if(s[i] == '0' && s[i+1] == '1'){
                        v.push_back(i);
                    }
                }
                else if(i == n-1){
                    if(s[i] == '0' && s[i-1] == '1'){
                        v.push_back(i);
                    }
                }
                else{
                    if(s[i] == '0' && (s[i-1]-'0' + s[i+1] -'0') == 1){
                        v.push_back(i);
                    }
                }
            }
            for(auto it: v){
                s[it] = '1';
            }
        }
        cout << s << endl;
    }
    return 0;
}
