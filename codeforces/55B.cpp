#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int solve(vector<int> a, string s){
    if((int)a.size() == 1) return a[0];
    int res = 1e18;
    for(int i = 0; i < (int)a.size(); i++){
        for(int j = i+1; j < (int)a.size(); j++){
            vector<int> b;
            for(int k = 0; k < (int)a.size(); k++){
                if(k != i && k != j) b.push_back(a[k]);
            }
            if(s[0] == '*'){
                b.push_back(a[i]*a[j]);
            }
            else{
                b.push_back(a[i]+a[j]);
            }
            res = min(res, solve(b, s.substr(1)));
        }
    }
    return res;
}

int32_t main(){
    vector<int> a(4);
    for(int i = 0; i < 4; i++) cin >> a[i];
    string s = "";
    char ch;
    for(int i = 0; i < 3; i++){
        cin >> ch;
        s += ch;
    }
    cout << solve(a, s) << "\n";
    return 0;
}
