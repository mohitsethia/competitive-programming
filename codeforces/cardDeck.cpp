#include<iostream>
#include<algorithm>
#include<cstdio>
#include<map>
#include<vector>
using namespace std;
void solve(){
    int n;
    cin >> n;
    int a[n];
    map<int, int> idx;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        idx[a[i]] = i;
    }
    vector<bool> visited(n, false);
    auto it = idx.end();
    --it;
    int k = 0;
    while(k < n){
        int index = it->second;
        if(index == 0){
            while(!visited[index] && index < n){
                cout << a[index] << " ";
                index++;
            }
            return;
        }
        while(!visited[index] && index < n){
            cout << a[index] << " ";
            idx.erase(a[index]);
            visited[index] = true;
            index++;
        }
        it = idx.end();
        it--;
        k++;
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
    return 0;
}
