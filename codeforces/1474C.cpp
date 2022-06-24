#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> a(2*n);
    int mx = 0;
    for(int i = 0; i < 2*n; i++){
        cin >> a[i];
        if(a[i] > a[mx]){
            mx = i;
        }
    }
    int ans = -1;
    for(int i = 0; i < 2*n; i++){
        if(i == mx){
            continue;
        }
        int x = a[mx];
        multiset<int> st;
        for(int j = 0; j < 2*n; j++){
            if(j == i || j == mx) continue;
            st.insert(a[j]);
        }
        bool ok = true;
        while(st.size()){
            int temp = *st.rbegin();
            st.erase(st.find(temp));
            if(st.find(x-temp) == st.end()){
                ok = false;
                break;
            }
            st.erase(st.find(x-temp));
            x = temp;
        }
        if(ok){
            ans = i;
        }
    }
    if(ans == -1){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    int x = a[mx] + a[ans];
    cout << x << endl;
    multiset<int> res;
    for(int i = 0; i < 2*n; i++){
        res.insert(a[i]);
    }
    while(res.size()){
        int temp = *res.rbegin();
        res.erase(res.find(temp));
        res.erase(res.find(x-temp));
        cout << temp << " " << x-temp << "\n";
        x = temp;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
