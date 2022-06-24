#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, cnta = 0, cntb = 0;
        cin >> n;
        string a, b;
        cin >> a >> b;
        for(int i = 0; i < n; i++){
            if(a[i] > b[i]){
                cnta++;
            }
            else if(a[i] < b[i]){
                cntb++;
            }
        }
        if(cnta > cntb){
            cout << "RED" << endl;
        }
        else if(cnta < cntb){
            cout << "BLUE\n";
        }
        else{
            cout << "EQUAL\n";
        }
    }
    return 0;
}
