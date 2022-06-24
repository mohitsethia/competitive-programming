#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
bool mycompare(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return b.second < a.second;
}
*/
int main(){
    int n;
    cin >> n;
    vector<pair<int, int> > v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].second >> v[i].first;
    }
    sort(v.begin(), v.end());
    int counter = 1, ans = 0, i = n-1;
    while(counter > 0 && i >= 0){
        counter += v[i].first;
        counter--;
        ans += v[i].second;
        i--;
    }
    cout << ans;
    return 0;
}
