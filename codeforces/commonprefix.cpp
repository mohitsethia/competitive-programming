#include<iostream>
#include<string>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s(200, 'a');
        cout << s << endl;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            s[a] = s[a] == 'a' ? 'b' : 'a';
            cout << s << endl;
        }
        
    }
    return 0;
}
