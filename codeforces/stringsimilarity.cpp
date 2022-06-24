#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        char in = s[n-1];
        for(int i = 0; i < n; i++){
            cout << in;
        }
        cout << endl;
    }
    return 0;
}
