#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution{
public:
    int minSwapsRequired(vector<int> &a){
        int n = a.size();
        vector<pair<int, int> > positions(n);
        for(int i = 0; i < n; i++){
            positions[i].first = a[i];
            positions[i].second = i;
        }
        sort(positions.begin(), positions.end());
        vector<bool> vis(n, false);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(vis[i] || positions[i].second == i){
                continue;
            }
            int cycle_size  = 0;
            int j = i;
            while(!vis[j]){
                vis[j] = true;
                j = positions[j].second;
                cycle_size++;
            }
            if(cycle_size) ans += cycle_size-1;
        }
        return ans;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    Solution *obj = nullptr;
    cout << obj->minSwapsRequired(a) << "\n";
    return 0;
}
