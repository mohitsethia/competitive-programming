#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define int long long
int32_t main(){
    int testcase;
    cin >> testcase;
    while(testcase--){
        int n;
        cin >> n;
        vector<int> t(n), x(n);
        for(int i = 0; i < n; i++){
            cin >> t[i] >> x[i];
        }
        int curr_pos = 0, next_pos = 0, next_time = 0, curr_time = 0, ans = 0, i = 0, j = 0;
        while(i < n){
            next_pos = x[i];
            curr_time = t[i];
            next_time = t[i] + abs(curr_pos - next_pos);
            if(i == n-1){
                ans++;
                break;
            }
            if(next_time <= t[i+1]){
                ans++;
            }
            i++;
            while(i < n && t[i] < next_time){
                if(curr_pos > next_pos){
                    j = max(curr_pos - (t[i] -curr_time), next_pos);
                    if(x[i] <= j && x[i] >= next_pos){
                        if(i == n-1){
                            ans++;
                            i++;
                            break;
                        }
                        if(curr_time + abs(x[i] - curr_pos) <= t[i+1]){
                            ans++;
                        }
                    }
                }
                else{
                    j = min(curr_pos + (t[i] - curr_time), next_pos);
                    if(x[i] >= j && x[i] <= next_pos){
                        if(i == n - 1){
                            ans++;
                            i++;
                            break;
                        }
                        if(curr_time + abs(x[i]-curr_pos) <= t[i+1]){
                            ans++;
                        }
                    }
                }
                i++;
            }
            curr_pos = next_pos;
            curr_time = next_time;
        }
        cout << ans << endl;
    }
    return 0;
}
