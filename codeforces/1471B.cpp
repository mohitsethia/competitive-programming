#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>

#define int long long

using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        int sum = 0;
        bool odd = false;
        deque<pair<int, int> > dq;
        for(int i = 0; i < n; i++){
            int z;
            cin >> z;
            dq.push_back({z, 1});
        }
        while(!dq.empty()){
            if(dq.front().first%x) odd = true;
            sum += dq.front().first*dq.front().second;
            if(dq.front().second > 1 && !odd && dq.front().first%x == 0){
                dq.push_back({dq.front().first/x, x*dq.front().second});
                dq.pop_front();
                continue;
            }
            if(dq.front().first%x == 0 && !odd){
                if(dq.size() > 1 && dq.front().first/x == dq.back().first)
                    dq.back().second += x;
                else
                    dq.push_back({dq.front().first/x, x});
            }
            else odd = true;
            dq.pop_front();
        }
        cout << sum << "\n";
    }
    return 0;
}
