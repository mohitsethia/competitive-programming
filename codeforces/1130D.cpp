#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n), small(n, 1e9+7);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        --a, --b;
        ++cnt[a];
        int dist = b-a;
        if(dist < 0) dist += n;
        small[a] = min(small[a], dist);
    }
    for(int start = 0; start < n; start++){
        int ans = 0;
        for(int a = 0; a < n; a++){
            if(cnt[a]){
                int dist = a - start;
                if(dist < 0) dist += n;
                ans = max(ans, n*(cnt[a]-1) + dist + small[a]);
            }
        }
        cout << ans << " ";
    }
    return 0;
}
