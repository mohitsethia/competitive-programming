#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
#define endl '\n'
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int top;
    cin >> top;
    vector<pair<int, int> > a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    int down = 7-top;
    bool flag = true;
    for(int i = 0; i < n; i++){
        if(a[i].first == top || a[i].first == down || (7-a[i].first) == top || (7-a[i].first) == down || a[i].second == top || a[i].second == down || (7-a[i].second) == top || (7-a[i].second) == down){
            flag = false;
            break;
        }
    }
    if(flag){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
    return 0;
}
