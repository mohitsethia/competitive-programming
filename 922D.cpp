#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

int32_t main(){
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    auto cnt = [&](string str){
        int count = 0;
        int res = 0;
        for(int i = 0; i < (int)str.size(); i++){
            if(str[i] == 's') count++;
            else res += count;
        }
        return res;
    };
    sort(s.begin(), s.end(), [&](const string &a, const string &b){
        return cnt(a+b) > cnt(b+a);
    });
    string ss;
    for(int i = 0; i < n; i++){
        ss += s[i];
    }
    cout << cnt(ss) << "\n";
    return 0;
}
