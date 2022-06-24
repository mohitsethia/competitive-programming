#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

#define int long long
using namespace std;

void find(vector<int> &a, vector<int> &pref, int l, int r, set<int> &st){
    int sum = pref[r]-pref[l-1];
    st.insert(sum);
    int mid = (a[l]+a[r])>>1;
    int pos = -1;
    for(int i = l; i <= r; i++){
        if(a[i] <= mid) pos = i;
        else break;
    }
    if(pos == -1 || pos == r) return;
    find(a, pref, l, pos, st);
    find(a, pref, pos+1, r, st);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<int> a(n+1);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<int> pref(n+1);
        for(int i = 1; i <= n; i++){
            pref[i] = pref[i-1]+a[i];
        }
        set<int> st;
        find(a, pref, 1, n, st);
        while(q--){
            int sum;
            cin >> sum;
            if(st.find(sum) != st.end()) cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}
