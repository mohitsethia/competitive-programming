#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    int t = 0, h = 0;
    for(int i = 0; i < n; i++){
        t += s[i] == 'T';
        h += s[i] == 'H';
    }
    int res = n;
    for(int i = 0; i < n; i++){
        int change = 0;
        int idx = i;
        for(int j = 0; j < h; j++){
            if(s[idx++] != 'H') change++;
            if(idx >= n) idx = 0;
        }
        for(int j = 0; j < t; j++){
            if(s[idx++] != 'T') change++;
            if(idx >= n) idx = 0;
        }
        res = min(res, change/2);
    }
    cout << res << "\n";
    return 0;
}
