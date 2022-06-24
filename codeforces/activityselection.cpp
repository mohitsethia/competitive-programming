#include<iostream>
#include<vector>
using namespace std;
bool mycompare(pair<int, int> v1, pair<int, int> v2){
    return v1.second < v2.second;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        pair<int, int> v[n];
        for(int i = 0; i < n; i++){
            int x, y;
            cin >> x >> y;
            v[i].first = x;
            v[i].second = y;   
        }
        sort(v, v + n, mycompare);
        int et = v[0].second;
        int ans = 1;
        for(int i = 1; i < n; i++){
            if(v[i].first >= et){
                ans++;
                et = v[i].second;
            }
        }
        cout << ans << endl;
    }
    return 0;
}   
