#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>

#define int long long

using namespace std;

int32_t main(){
    int n;
    cin >> n;
    vector<int> a(2*n);
    for(int i = 0; i < 2*n; i++){
        char c;
        cin >> c;
        if(c == '-') cin >> a[i];
    }
    vector<int> curr, ans;
    for(int i = 2*n-1; i >= 0; i--){
        if(!a[i]){
            if(curr.empty()){
                cout << "NO\n";
                return 0;
            }
            ans.push_back(curr.back());
            curr.pop_back();
            continue;
        }
        if(!curr.empty() && curr.back() < a[i]){
            cout << "NO\n";
            return 0;
        }
        curr.push_back(a[i]);
    }
    reverse(ans.begin(), ans.end());
    cout << "YES\n";
    for(int i: ans){
        cout << i << " ";
    }
    return 0;
}
