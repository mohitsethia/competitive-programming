#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main(){
    string s, t;
    cin >> s >> t;
    if(t.length() > s.length()){
        cout << s << "\n";
        return 0;
    }
    vector<int> z(t.size());

    for (int i = 1, l = 0, r = 0; i < (int)t.size(); ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < (int)t.size() && t[z[i]] == t[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }

    int p = -1;
    for(int i = 1; i < (int)t.size(); i++){
        if(z[i] + i == (int)t.size()){
            p = i;
            break;
        }
    }
    if(p == -1) p = t.size();

    int s0 = 0, s1 = 0;
    for(char ch: s){
        s0 += ch == '0';
        s1 += ch == '1';
    }
    int t0 = 0, t1 = 0;
    for(int i = 0; i < p; i++){
        t0 += t[i] == '0';
        t1 += t[i] == '1';
    }

    int mul = 1e6;
    
    if(t0 != 0) mul = min(mul, s0/t0);
    if(t1 != 0) mul = min(mul, s1/t1);
    string tp = t.substr(0, p);
    for(int i = 0; i < mul; i++){
        cout << tp;
        s0 -= t0;
        s1 -= t1;
    }

    int idx = 0;
    while(s0 != 0 && s1 != 0){
        cout << t[idx];
        if(t[idx] == '0') --s0;
        else --s1;
        idx++;
        if(idx == p) idx = 0;
    }
    cout << string(s0, '0');
    cout << string(s1, '1');
    return 0;
}
