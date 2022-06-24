#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

#define int long long

bool Check(vector<pair<int, int> > &a, int mid, int k){
    int ans = 0;
    for(int i = a.size()-1; i >= 0; i--){
        int mx = a[i].first/mid;
        // mx = min(mx, a[i].first);
        if(mx == 0) return false;
        ans += mx;
        if(ans >= k) return true;
    }
    return false;
}
int GetCount(vector<pair<int, int> > &a, int n, int k){
    int low = 0, high = 1e10;
    int ans = 1;
    while(low <= high){
        int mid = (low+high)/2;
        if(Check(a, mid, k)){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans > n ? n : ans;
}

int32_t main(){
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        mp[x]++;
    }
    vector<pair<int, int> > a;
    for(auto it: mp){
        a.push_back({it.second, it.first});
    }
    sort(a.begin(), a.end());
    int ans = GetCount(a, n, k);
    int cnt = 0;
    for(int i = a.size()-1; i >= 0; i--){
        if(cnt == k) break;
        int req = k -cnt;
        int mx = a[i].first/ans;
        // mx = min(mx, a[i].first);
        req = min(req, mx);
        cnt += req;
        for(int j = 0; j < req; j++){
            cout << a[i].second << ' ';
        }
    }
    return 0;
}
