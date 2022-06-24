#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int32_t main(){
    int n;
    cin >> n;
    vector<vector<int>> v;
    for(int i = 0; i < n; i++){
        int x, y, z;
        cin >> x >> y >> z;
        v.push_back({x, y, z, i});
    }
    while(!v.empty()){
        sort(v.begin(), v.end());
        int x = v.back()[0];
        int y = v.back()[1];
        int z = v.back()[2];
        int pos = v.back()[3];
        int ind = 0;
        v.pop_back();
        int d = 1e10;
        for(int i = 0; i < v.size(); i++){
            int dist = abs(v[i][0]-x);
            dist += abs(v[i][1]-y);
            dist += abs(v[i][2]-z);
            if(dist < d){
                d = dist;
                ind = i;
            }
        }
        cout << pos+1 << " " << v[ind][3]+1 << "\n";
        v.erase(v.begin()+ind);
    }
    return 0;
}
