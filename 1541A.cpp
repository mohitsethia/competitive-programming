#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<climits>

using namespace std;
using ll = long long;

#define vi vector<int>
#define pi pair<int, int>
#define vii vector<pi>
#define pb push_back
#define mk make_pair
#define pii pair<int, pair<int, int> >
#define mi map<int, int>

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    int p = 2;
    for(int i = 0; i < n; i += 2){
        a[i] = p;
        p += 2;
        if(p > n) break;
    }
    p = 1;
    for(int i = 1; i < n; i += 2){
        a[i] = p;
        p += 2;
    }
    if(n%2 == 1){
        a[n-1]  = n;
        swap(a[n-1], a[n-2]);
    }
    for(auto &it: a){
        cout << it << " ";
    }
    cout << "\n";
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
