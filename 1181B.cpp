#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

string add(string s,string t){
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    if(s.size() > t.size()){
        swap(s,t);
    }
    while(s.size() < t.size()){
        s.push_back('0');
    }
    string res;
    int n = s.size();
    int c = 0;
    for(int i = 0; i < n; i++){
        int d = s[i] + t[i] + c - '0' - '0';
        c = d / 10;
        d %= 10;
        res.push_back(d + '0');
    }
    if(c){
        res.push_back(c + '0');
    }
    reverse(res.begin(), res.end());
    return res;
}
string s;
string best;

void split(int x){
    if(s[x] == '0') return;
    string a = s.substr(0,x);
    string b = s.substr(x);
    string ans = add(a,b);
    if(ans.size() < best.size() || (ans.size() == best.size() && ans < best)){
        best = ans;
    }
}

void solve(){
    int n;
    cin >> n;
    cin >> s;

    for(int i = 0; i < n; i++){
        best.push_back('9');
    }

    int mid = n / 2;
    int tmp = max(1LL,mid);
    for(int i = 0; i < 3; i++){
        split(tmp++);
        while(tmp < n && s[tmp] == '0') tmp++;
        if(tmp == n) break;
    }

    tmp = max(1LL,mid);
    for(int i = 0; i < 3; i++){
        split(tmp--);
        while(tmp > 0 && s[tmp] == '0') tmp--;
        if(tmp == 0) break;
    }
    cout << best;
}

int32_t main(){
    solve();
    return 0;
}
