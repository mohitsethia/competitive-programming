#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = i+1; j < n; j++){
                if(v[j] > v[i]){
                    break;
                }
                else if(v[i] == v[j]){
                    cnt++;
                }
            }
            for(int j = i-1; j >= 0; j--){
                if(v[j] > v[i]){
                    break;
                }
                else if(v[i] == v[j]){
                    cnt++;
                }
            }
            cout << cnt << " ";
        }
        cout << "\n";
    }
    return 0;
}
