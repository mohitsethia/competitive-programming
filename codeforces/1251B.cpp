#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> sz(n);
        int c0 = 0, c1 = 0;
        int p = 0;
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            for(auto c: s){
                if(c == '0') c0++;
                else c1++;
            }
            p += s.size()/2;
        }
        int can_p = c0/2 + c1/2;
        if(p <= can_p){
            cout << n << "\n";
        }
        else{
            cout << n-1 << "\n";
        }
    }
    return 0;
}
