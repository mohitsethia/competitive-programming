#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        string b = s;
        sort(b.begin(), b.end());
        int k = 0;
        for(int i = 0; i < n; i++){
            if(s[i] != b[i]){
                k++;
            }
        }
        cout << k << "\n";
    }
    return 0;
}
