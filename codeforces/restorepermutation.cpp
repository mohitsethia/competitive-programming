#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[2*n];
        set<int> s;
        for(int i = 0; i < 2*n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < 2*n; i++){
            if(s.find(a[i]) == s.end()){
                cout << a[i] << " ";
                s.insert(a[i]);
            }
        }
        cout << endl;
    }
    return 0;
}
