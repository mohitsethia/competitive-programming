#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

bool comp(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b){
    return a.first.second < b.first.second;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int > > inc, dec;
    for(int i = 0; i < n; i++){
        int u, v;
        cin >> u >> v;
        if(u < v){
            inc.push_back({{u, v}, i});
        }
        else{
            dec.push_back({{u, v}, i});
        }
    }
    if(inc.size() > dec.size()){
        sort(inc.begin(), inc.end(), greater<pair<pair<int, int>, int>>());
        cout << inc.size() << "\n";
        for(int i = 0; i < (int)inc.size(); i++){
            cout << inc[i].second+1 << " ";
        }
    }
    else{
        sort(dec.begin(), dec.end(), comp);
        cout << dec.size() << "\n";
        for(int i = 0; i < (int)dec.size(); i++){
            cout << dec[i].second+1 << " ";
        }
    }
    return 0;
}



