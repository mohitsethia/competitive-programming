#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

#define int long long
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> freq;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        freq[a[i]]++;
    }
    int maxFreq = 0, maxEle;
    for(auto it: freq){
        if(maxFreq < it.second){
            maxEle = it.first;
            maxFreq = it.second;
        }
    }
    if(maxFreq == n){
        cout << "0\n";
        return 0;
    }
    vector<pair<int, pair<int, int> > > res;
        int pos = -1;
        for(int i = 0; i < n; i++){
            if(a[i] == maxEle){
                pos = i;
                break;
            }
        }
        for(int k = pos+1; k < n; k++){
            if(a[k] == a[k-1]) continue;
            if(a[k] > a[k-1]){
                res.push_back({2, {k, k-1}});
            }
            else{
                res.push_back({1, {k, k-1}});
            }
            a[k] = a[k-1];
        }
        for(int k = pos-1; k >= 0; k--){
            if(a[k] == a[k+1]) continue;
            if(a[k] > a[k+1]){
                res.push_back({2, {k, k+1}});
            }
            else{
                res.push_back({1, {k, k+1}});
            }
            a[k] = a[k+1];
        }
    cout << res.size() << "\n";
    for(auto it: res){
        cout << it.first << " " << it.second.first+1 << " " << it.second.second+1 << "\n";
    }
    return 0;
}
