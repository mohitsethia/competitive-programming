#include<iostream>
#include<algorithm>

#define int long long

using namespace std;

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i < n; i++){
            cout << "9";
        }
        cout << "3\n";
    }
    return 0;
}
