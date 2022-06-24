#include<iostream>
#include<algorithm>
using namespace std;
void solve(){
    int n;
    cin >> n;
    int cnt[3] = {0};
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        cnt[x%3]++;
    }
    int res = 0;
    while(*min_element(cnt, cnt+3) != n/3){
        for(int i = 0 ;i < 3; i++){
            if(cnt[i] > n/3){
                res++;
                cnt[i]--;
                cnt[(i+1)%3]++;
            }
        }
    }
    cout << res << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
