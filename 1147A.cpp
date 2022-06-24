#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    pair<int, int> m[100025];
    for(int i = 0; i <= n; i++){
        m[i].first = 200000; // min
        m[i].second = -1; // max
    }
    int x;
    for(int i = 1; i <= k; i++){
        cin >> x;
        m[x].first = min(m[x].first, i);
        m[x].second = max(m[x].second, i);
    }
    int sum = 0;
    for(int i = 1; i <= n; i++){
        if(m[i].second == -1 && m[i].first == 200000) sum++;
        if(i != 1){
            if(m[i].second < m[i-1].first || m[i-1].second == -1 && m[i-1].first == 200000) sum++;
        }
        if(i != n){
            if(m[i].second < m[i+1].first || m[i+1].second == -1 && m[i+1].first==200000) sum++;
        }
    }
    cout << sum << endl;
    return 0;
}
