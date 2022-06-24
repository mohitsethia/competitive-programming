#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
#define int long long
int32_t main(){
    int n;
    cin >> n;
    vector<int> box(n), cnt(101, 0);
    for(int i = 0; i < n; i++){
        cin >> box[i];
        cnt[box[i]]++;
    }
    sort(box.begin(), box.end());
    int tc = 101, ans = 0;
    while(tc--){
        int count = 0, x = 0;
        for(int i = 0; i < 101; i++){
            if(cnt[i] == 0){
                x++;
                continue;
            }
            int cc = count;
            //count maintains how many it can store on the top of that pile
            count += min(cnt[i], i+1-cc);
            cnt[i] -= min(cnt[i], i+1-cc);
        }
        if(count > 0) ans++;
        if(x == 101) break;
    }
    cout << ans << endl;
    return 0;
}
