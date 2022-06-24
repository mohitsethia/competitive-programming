#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        int diff = abs(a-b)-1;
        vector<int> v(m);
        for(int i = 0; i < m; i++) cin >> v[i];
        sort(v.begin(), v.end());
        int last = 0;
        if(a < b){
            last = b-1;
        }
        else{
            last = n-b;
        }
        int ans = 0;
        int low = 0, high = min(diff, m);
        while(low <= high){
            int mid = (low+high)/2;
            bool can_be = 1;
            for(int i = 0; i < mid; i++){
                if(v[mid-i-1]+i+1 > last){
                    can_be = 0;
                    break;
                }
            }
            if(can_be){
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        cout << ans << "\n";
    }
    return 0;
}
