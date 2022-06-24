#include<iostream>
#include<vector>
#include<climits>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    int tc = 1;
    while(tc <= t){
        int n;
        cin >> n;
        int a[n], diff;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        diff = a[1] - a[0];
        int cnt = 2;
        vector<int> v;
        for(int i = 1; i < n-1; i++){
            if(diff == (a[i+1] - a[i])){
                cnt++;
                
            }
            else{
                diff = a[i+1] - a[i];
                v.push_back(cnt);
                cnt = 2;
            }
            if(i == n-2){
                v.push_back(cnt);
            }
        }
        int mx = INT_MIN;
        for(auto i:v){
            if(i > mx){
                mx = i;
            }
//            cout << i << " ";
        }
        cout << "Case #" << tc++ << ": " << mx << endl;
    }
    return 0;
}
