#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    if(s[0] == '.' || s[n-1] == '.'){
        cout << "NO\n";
        return 0;
    }
    vector<string> res;
    vector<int> p;
    for(int i = 0; i < n; i++){
        if(s[i] == '.') p.emplace_back(i);
    }
    if((int)p.size() == 0){
        cout << "NO\n";
        return 0;
    }
    for(int i = 1; i < (int)p.size(); i++){
        if(p[i]-p[i-1]-1 < 2 || p[i]-p[i-1]-1 > 11){
            cout << "NO\n";
            return 0;
        }
    }
    int last = 0;
    if(p[0] > 8){
        cout << "NO\n";
        return 0;
    }
    for(int i = 1; i < (int)p.size(); i++){
        if(p[i]-p[i-1]-1 > 3){
            res.push_back(s.substr(last, p[i-1]+4-last));
            last = p[i-1]+4;
        }
        else if(p[i]-p[i-1]-1 > 2){
            res.push_back(s.substr(last, p[i-1]+3-last));
            last = p[i-1]+3;
        }
        else if(p[i]-p[i-1]-1 > 1){
            res.push_back(s.substr(last, p[i-1]+2-last));
            last = p[i-1]+2;
        }
        else{
            cout << "NO\n";
            return 0;
        }
    }
    res.push_back(s.substr(last));
    if(n-p[(int)p.size()-1]-1 > 3){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for(auto &it: res){
        cout << it << endl;
    }
    return 0;
}
