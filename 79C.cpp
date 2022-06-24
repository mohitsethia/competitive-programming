#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

const int N = 1e5;

int ll[N];

int32_t main(){
    string s;
    cin >> s;
    int n = s.length();
    fill(ll, ll+n, -1);
    int k;
    cin >> k;
    while(k--){
        string t;
        cin >> t;
        int m = t.length();
        for(int j = m-1; j < n; j++){
            bool yes = true;
            for(int h = 0; h < m; h++){
                if(s[j-h] != t[m-1-h]){
                    yes = false;
                    break;
                }
            }
            if(yes)
                ll[j] = max(ll[j], j-m+1);
        }
    }
    int len = 0, pos = 0;
    for(int l = -1, j = 0; j < n; j++){
        l = max(l, ll[j]);
        if(len < j-l){
            len = j-l;
            pos = l+1;
        }
    }
    cout << len << " " << pos << "\n";
    return 0;
}
