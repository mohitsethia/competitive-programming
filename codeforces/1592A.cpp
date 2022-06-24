#include<iostream>
#include<algorithm>
#include<vector>

#define int long long

using namespace std;

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, h;
        cin >> n >> h;
        vector<int> weapon(n);
        for(int i = 0; i < n; i++){
            cin >> weapon[i];
        }
        sort(weapon.begin(), weapon.end(), greater<int>());
        int low = 1, high = 1e9;
        int ans = 0;
        while(low <= high){
            int mid = (low+high)/2;
            if((mid%2 && (mid+1)/2*weapon[0]+(mid/2)*weapon[1] >= h) || (mid%2 == 0 && (mid/2)*weapon[0] + (mid/2)*weapon[1] >= h)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
