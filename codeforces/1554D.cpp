#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n == 1){
            cout << "a\n";
            continue;
        }
        string s = "";
        while((int)s.length() < n/2)
            s += 'a';
        if(n%2) s += "bc";
        else s += 'b';
        while((int)s.length() < n) s += 'a';
        cout << s << "\n";
    }
    return 0;
}
