#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

int calc(int &time, int each, int score){
    if(240-time < each) return 0;
    if(time + each*20 <= 240){
        time += each*20;
        return score*20;
    }
    else{
        int rem = 240-time;
        int left = rem/each;
        if(time + left*each > 240) return 0;
        time += left*each;
        return left*score;
    }
    return 0;
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        vector<pair<int, int> > a(3);
        for(int i = 0; i < 3; i++){
            cin >> a[i].first;
        }
        for(int i = 0; i < 3; i++){
            cin >> a[i].second;
        }
        int res = 0;
        for(int i = 0; i <= 20; i++){
            for(int j = 0; j <= 20; j++){
                for(int k = 0; k <= 20; k++){
                    int time = a[0].first*i + a[1].first*j + a[2].first*k;
                    if(time > 240) break;
                    res = max(res, a[0].second*i + a[1].second*j +a[2].second*k);
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}
