#include<iostream>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int count[2] = {};
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            count[a%2]++;
        }
        if(count[0] && count[1]){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
    return 0;
}
