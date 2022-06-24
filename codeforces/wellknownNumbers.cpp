#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define int long long
int32_t main(){
    int s, k;
    cin >> s >> k;
    int f[100000] = {0};
    f[1] = 1;
    int i = 1;
    while(1){
        if(f[i] > s){
            break;
        }
        i++;
        for(int j = max(1ll, i-k); j < i; j++){
            f[i] += f[j];
        }
    }
    vector<int> ans;
    ans.push_back(0);
    for(int j = i; j > 0; j--){
        if(f[j] <= s){
            ans.push_back(f[j]);
            s -= f[j];
        }
    }
    cout << ans.size() << endl;
    for(int& i: ans){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
