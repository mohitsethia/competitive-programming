#include<iostream>
#include<map>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        map<int , int> mp;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            mp[a[i]]++;
        }
        int mn = INT_MAX;
        for(auto it : mp){
            if(it.second == 1){
                mn = min(mn, it.first);
            }
        }
        if(mn == INT_MAX){
            cout << "-1" << endl;
            continue;
        }
        for(int i = 0; i < n; i++){
            if(a[i] == mn){
                cout << i+1 << endl;
                break;
            }
        }
    }
    return 0;
}
