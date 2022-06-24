#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<int> cnt(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    vector<vector<vector<vector<int> > > > dp(101, vector<vector<vector<int> > >(101, vector<vector<int> >(101, vector<int>(2, (int)1e9))));
    int even = 0, odd = 0;
    for(int i = 1; i <= n; i++){
        if(cnt[i] == 0){
            if(i%2) odd++;
            else even++;
        }
    }
    dp[0][even][odd][1] = 0;
    dp[0][even][odd][0] = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] == 0){
            for(int ev = 0; ev <= n; ev++){
                for(int od = 0; od <= n; od++){
                    if(ev > 0){
                        dp[i][ev-1][od][0] = min(dp[i][ev-1][od][0], dp[i-1][ev][od][0]);
                        dp[i][ev-1][od][0] = min(dp[i][ev-1][od][0], dp[i-1][ev][od][1]+1);
                    }
                    if(od > 0){
                        dp[i][ev][od-1][1] = min(dp[i][ev][od-1][1], dp[i-1][ev][od][1]);
                        dp[i][ev][od-1][1] = min(dp[i][ev][od-1][1], dp[i-1][ev][od][0]+1);
                    }
                }
            }
        }
        else{
            int curr = a[i]%2;
            for(int ev = 0; ev <= n; ev++){
                for(int od = 0; od <= n; od++){
                    for(int j = 0; j < 2; j++){
                        dp[i][ev][od][curr] = min(dp[i][ev][od][curr], dp[i-1][ev][od][j] + (j == curr ? 0 : 1));
                    }
                }
            }
        }
    }
    int ans = min(dp[n][0][0][0], dp[n][0][0][1]);
    cout << ans << "\n";
    return 0;
}
