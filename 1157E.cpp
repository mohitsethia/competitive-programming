#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<climits>

#define int long long
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    multiset<int> b;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        b.insert(x);
    }
    vector<int> c;
    for(int i = 0; i < n; i++){
        int p = n-a[i];
        auto it = b.find(p);
        if(it != b.end()){
            b.erase(it);
            c.push_back(0);
        }
        else{
            auto ct = b.lower_bound(p);
            if(ct == b.end()){
                c.push_back(*b.begin());
                c.back() += a[i];
                c.back() %= n;
                b.erase(b.begin());
            }
            else{
                c.push_back(*ct);
                c.back() += a[i];
                c.back() %= n;
                b.erase(ct);
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << c[i] << " \n"[i == n-1];
    }
    return 0;
}
