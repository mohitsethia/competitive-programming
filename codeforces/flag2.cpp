#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
#define endl '\n'
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> color(26, 0);
    int ans = 0;
    for(int i = 0; i < n; i++){
        color = vector<int>(26, 0);
        for(int j = 0; j < n; j++){
            char c;
            cin >> c;
            color[c-'a']++;
        }
        sort(color.begin(), color.end(), greater<int>());
        for(int i = 23; i >= 0; i--){
            if(color[i] == 0){
                break;
            }
            ans += color[i];
        }
    }
    cout << ans << endl;
    return 0;
}
