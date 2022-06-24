#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int32_t main(){
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    int dot = -1, greater = -1;
    for(int i = 0; i < n; i++){
        if(s[i] == '.') dot = i;
        else if(dot != -1 && s[i] >= '5'){
            greater = i;
            break;
        }
    }
    if(greater == -1 || dot == -1){
        cout << s << "\n";
        return 0;
    }
    greater++;
    s.resize(greater);
    while(--greater){
        if(s[greater] >= '5' && t){
            s[greater-1]++;
            t--;
        }
        else break;
    }
    if(s[greater] == '.'+1){
        int l = --greater;
        s[l]++;
        while(s[l] > '9'){
            s[l] = '0';
            if(l-- == 0) s = '1' + s, greater++;
            else s[l]++;
        }
    }
    cout << s.substr(0, greater+1) << "\n";
    return 0;
}
