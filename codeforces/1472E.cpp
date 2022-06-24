#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<pair<int, int>, int> > friends;
        for(int i = 0; i < n; i++){
            int h, w;
            cin >> h >> w;
            friends.push_back({{h, -w}, i});
            friends.push_back({{w, -h}, i});
        }
        sort(friends.begin(), friends.end());
        vector<int> ans(n, -2);
        int min_height = 1e9;
        int min_idx = -1;
        for(auto fr: friends){
            int h = -fr.first.second;
            int idx = fr.second;
            if(h > min_height){
                ans[idx] = min_idx;
            }
            else if(h < min_height){
                min_height = h;
                min_idx = idx;
            }
        }
        for(int i: ans){
            cout << i+1 << " ";
        }
        cout << "\n";
    }
    return 0;
}
