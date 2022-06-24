#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n+1];
    memset(a, 0, sizeof a);
    vector<pair<int, int> > dec;
    for(int i = 0; i < m; i++){
        int t, l, r;
        cin >> t >> l >> r;
        if(t == 1){
            for(int k = l+1; k <= r; k++){
                a[k] = 1;
            }
        }
        else{
            dec.push_back({l, r});
        }
    }
    for(int i = 0; i < (int)dec.size(); i++){
        bool found = false;
        for(int j = dec[i].first+1; j <= dec[i].second; j++){
            if(a[j] == 0){
                found = true;
                break;
            }
        }
        if(!found){
            cout << "NO\n";
            return 0;
        }
    }
    int curr = 2000;
    cout << "YES\n";
    for(int i = 1; i <= n; i++){
        if(a[i] == 1){
            curr++;
        }
        else{
            curr--;
        }
        cout << curr << ' ';
    }
    return 0;
}
