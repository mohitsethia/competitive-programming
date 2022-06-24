#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

#define int long long 
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        int Mex = a;
        int Xor = 0;
        Mex--;
        if(Mex%4 == 0) Xor = Xor^Mex;
        else if(Mex%4 == 1) Xor ^= 1;
        else if(Mex%4 == 2) Xor ^= a;
        Mex++;
        if(Xor == b){
            cout << Mex << "\n";
        }
        else{
            if((Xor^b) == a){
                cout << Mex+2 << "\n";
            }
            else{
                cout << Mex+1 << "\n";
            }
        }
    }
    return 0;
}
