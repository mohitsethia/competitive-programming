#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
const int N = 101;
int n, m;
vector<vector<int> > a(N, vector<int>(N));
vector<int> ans;

void test(int x){
    vector<pair<int, int> > diff;
    int sum = 0;
    for(int i = 0; i < m; i++){
        diff.push_back({a[i][x]-a[i][n-1], i});
        sum += diff.back().first;
    }
    sort(diff.begin(), diff.end());
    vector<int> bad;
    for(auto t: diff){
        if(sum < 0){
            sum -= t.first;
            bad.emplace_back(t.second);
        }
    }
    if(bad.size() < ans.size()){
        ans = bad;
    }
}

int main(){

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < m; i++){
        ans.emplace_back(i);
    }
    for(int i = 0; i < n-1; i++){
        test(i);
    }

    cout << (int)ans.size() << "\n";
    for(auto it: ans){
        cout << it+1 << " ";
    }
    cout << "\n";
    return 0;
}
