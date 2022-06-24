#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        bool bad = false;
        bool done = false;
        for(int i = 0; i < n; i++){
            if(s[i] != t[i] && !done){
                // int id = -1;
                for(int j = i+1; j < n; j++){
                    if(s[j] != t[j] && t[i] == t[j]){
                        done = true;
                        swap(s[i], t[j]);
                        break;
                    }
                }
                if(!done){
                    bad = true;
                    break;
                }
            }
            if(s[i] != t[i] && done){
                bad = true;
                break;
            }
        }
        if(bad){
            cout << "No\n";
        }
        else{
            cout << "Yes\n";
        }
    }
    return 0;
}
