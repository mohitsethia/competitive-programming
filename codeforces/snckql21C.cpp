#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define int long long

bool myComparator(pair<int, int> &a, pair<int, int> &b){
    return a.second < b.second;
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int, int> > a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.begin(), a.end());
        int cnt = 0;
        for(int i = 0; i < n; i++) if(a[i].first > cnt) a[i].first = cnt++;
        sort(a.begin(), a.end(), [&](const pair<int, int> &p, const pair<int, int> &q){return p.second < q.second;});
        for(int i = 0; i < n; i++){
            cout << a[i].first << " ";
        }
        cout << "\n";
    }
    return 0;
}
