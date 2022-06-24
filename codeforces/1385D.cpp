#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int solve(const string& s, char c){
    if(s.size() == 1){
        return (s[0] != c);
    }
    int mid = s.size()/2;
    int cnt1 = solve(string(s.begin(), s.begin() + mid), c+1);
    cnt1 += s.size()/2 - count(s.begin()+mid, s.end(), c);
    int cnt2 = solve(string(s.begin()+mid, s.end()), c+1);
    cnt2 += s.size()/2 - count(s.begin(), s.begin()+mid, c);
    return min(cnt1, cnt2);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        cout << solve(s, 'a') << endl;
    }
    return 0;
}
