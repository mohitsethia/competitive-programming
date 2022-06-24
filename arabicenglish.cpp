#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<string> s(n);
        for(int i = 0; i < n; i++){
            cin >> s[i];
        }
        reverse(s.begin(), s.end());
        for(auto i: s){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
