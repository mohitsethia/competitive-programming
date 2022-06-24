#include<iostream>
#include<algorithm>
#include<climits>
#include<cmath>
#include<string>
#include<map>
using namespace std;
int main(){
    string s;
    cin >> s;
    int k, mx = 0;
    cin >> k;
    map<char, int> mp;
    char c;
    for(int i = 0; i < 26; i++){
        int x;
        cin >> x;
        mp[i+'a'] = x;
        if(x > mx){
            mx = x;
            c = i+'a';
        }
    }
    long long int res = 0;
    for(int i = 0; i < s.length(); i++){
        res += (i+1)*mp[s[i]];
    }
    if(mx != 0){
        int len = s.length() + 1;
        while(k--){
            res += (len++)*mx;
        }
    }
    cout << res << endl;
    return 0;
}
