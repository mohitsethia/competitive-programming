#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define int long long
void solve(){
    int season, total_min = 0;
    cin >> season;
    int intro[season];
    for(int i = 0; i < season; i++){
        cin >> intro[i];
    }
    for(int j = 0; j < season; j++){
        int episode;
        cin >> episode;
        for(int i = 0; i < episode; i++){
            int x;
            cin >> x;
            if(i == 0){
                total_min += x;
            }
            else{
                total_min += (x-intro[j]);
            }
        }
    }
    cout << total_min << endl;
}
int32_t main(){
    int t = 0;
    cin >> t;

    while(t--){
        solve();
    }
    return 0;
}
