#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int main(){
    int n, k, mn = INT_MAX, mx = INT_MIN;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        mn = min(mn, v[i]);
        mx = max(mx, v[i]);
    }
    if(mx - mn > k){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for(auto i : v){
        int in = 1, j = 0;
        while(j < i){
            cout << in << " ";
            in++;
            j++;
            if(in > k){
                in = 1;
            }
        }
        cout << endl;
    }
    return 0;
}
