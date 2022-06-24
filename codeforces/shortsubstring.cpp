#include<iostream>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        string a;
        cin >> a;
        cout << a[0];
        for(int i = 1; i < a.length()-1; i+=2){
            cout << a[i];
        }
        cout << a[a.length()-1] << endl;
    }
    return 0;
}
