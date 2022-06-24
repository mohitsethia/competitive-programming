#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        string order = "";
        vector<bool> have(26, 0);
        for(int i = (int)s.length()-1; i >= 0; i--){
            if(!have[s[i]-'a']){
                have[s[i]-'a'] = true;
                order += s[i];
            }
        }
        // cout << order << "\n";
        reverse(order.begin(), order.end());
        int n = s.length();
        int l = 0, r = n-1;
        bool ok = false;
        while(l <= r){
            int mid = (l+r)>>1;
            string k = "";
            vector<bool> done(26, false);
            string f = s.substr(0, mid+1);
            for(char c: order){
                for(char x: f){
                    if(!done[x-'a']) k += x;
                }
                done[c-'a'] = true;
            }
            if(k == s){
                cout << f << " " << order << "\n";
                ok = true;
                break;
            }
            else if((int)k.length() >= (int)s.length()){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        if(!ok)
            cout << "-1\n";
    }
    return 0;
}
