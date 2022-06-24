#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        int cnt = 0;
        for(int i = 0; i < n-2; i++){
            string t;
            cin >> t;
            if(i == 0 || t[0] != s.back()) s += t, cnt++;
            else s += t.back();
        }
        if(cnt == 1) s += 'a';
        cout << s << "\n";
    }
    return 0;
}
