#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        string str, res = "";
        cin >> str;
        int n = str.length();
        int cntP = 0, cntR = 0, cntS = 0;
        for(int i = 0; i < n; i++){
            if(str[i] == 'R'){
                cntP++;
            }
            else if(str[i] == 'P'){
                cntS++;
            }
            else{
                cntR++;
            }
        }
        int p = (cntP >= cntR) ? ((cntP >= cntS) ? 1 : 0) : 0;
        int r = (cntR >= cntP) ? ((cntR >= cntS) ? 1 : 0) : 0;
        int s = (cntS >= cntP) ? ((cntS >= cntR) ? 1 : 0) : 0;
        if(p){
            for(int i = 0; i < n; i++){
                res += 'P';
            }
        }
        else if(r){
            for(int i = 0; i < n; i++){
                res += 'R';
            }
        }
        else{
            for(int i = 0; i < n; i++){
                res += 'S';
            }
        }
        cout << res << endl;
    }
    return 0;
}
