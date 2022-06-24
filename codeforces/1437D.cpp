#include<iostream>
#include<algorithm>
#include<vector>

#define int long long

using namespace std;

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int depth = 0;
        auto inAsc = [&](vector<int> &v){
            for(int i = 1; i < (int)v.size(); i++){
                if(v[i] < v[i-1]) return i;
            }
            return (int)v.size();
        };
        vector<int> height(n, (int)1e6);
        height[0] = 0;
        height[1] = 1;
        for(int i = 1; i < n; i++){
            if(i-1 > 0 && a[i] < a[i-1]) depth++;
            height[i] = height[depth]+1;
        }
        cout << height[n-1] << "\n";
    }
    return 0;
}
