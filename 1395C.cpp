#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    int ans = 0;
    vector<int> res;
    for(int i = 0; i <= 1024; i++){
        res.clear();
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                if(((a[j]&b[k])|i) == i){
                    res.emplace_back(a[j]&b[k]);
                    break;
                }
            }
        }
        if((int)res.size() == n){
            break;
        }
    }
    for(int i = 0; i < n; i++){
        ans |= res[i];
    }
    cout << ans << "\n";
    return 0;
}
