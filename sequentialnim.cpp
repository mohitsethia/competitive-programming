#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int i = 0;
        while(i < n && a[i] == 1){
            i++;
        }
        if(i == n){
            if(i % 2 == 0){
                cout << "Second" << endl;
            }
            else{
                cout << "First" << endl;
            }
        }
        else{
            if(i%2 == 0){
                cout << "First" << endl;
            }
            else{
                cout << "Second" << endl;
            }
        }
    }
    return 0;
}
