#include<iostream>
using namespace std;
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        string a, b;
        cin >> n >> k >> a >> b;
        int have[26] = {}, need[26] = {};
        for(auto i : a){
            have[i-'a']++;
        }
        for(auto i : b){
            need[i-'a']++;
        }
        bool bad = false;
        for(int i = 0; i < 26; i++){
            if(have[i] < need[i] || (have[i] -= need[i]) % k){
                bad = true;
            }
            have[i+1] += have[i];
        }
        cout << (bad ? "NO" : "YES") << endl;
    }
    return 0;
}
