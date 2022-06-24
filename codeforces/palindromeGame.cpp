#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        int zero = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                zero++;
            }
        }
        if(zero != 1 && zero%2){
            cout << "ALICE\n";
        }
        else{
            cout << "BOB\n";
        }
    }
    return 0;
}
