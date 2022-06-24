#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<string> s;
    string a, b;
    cin >> a >> b;
    s.emplace_back(a);
    s.emplace_back(b);
    int cnt = 0;
    int n = (int)a.length();
    int empty = 0;
    for(int i = 0; i < n; i++){
        int curr = (s[0][i] == '0') + (s[1][i] == '0');
        empty += curr;
        if(empty >= 3){
            empty -= 3;
            cnt++;
        }
        else{
            empty = curr;
        }
    }
    cout << cnt << "\n";
    return 0;
}
