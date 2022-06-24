#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k, a, b;
    cin >> k >> a >> b;
    string s;
    cin >> s;
    int n = s.length();
    if(a*k > n || b*k < n){
        cout << "No solution\n";
        return 0;
    }
    int EachGroup = n/k;
    int left = n - (n/k)*k;
    string res = "";
    vector<string> ans;
    int p = 0;
    while(k--){
        for(int i = 0; i < EachGroup; i++){
            res += s[p++];
        }
        if(left){
            res += s[p++];
            left--;
        }
        ans.push_back(res);
        res = "";
    }
    for(auto &it: ans){
        cout << it << "\n";
    }
    return 0;
}
