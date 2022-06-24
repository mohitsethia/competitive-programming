#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> maxi(n+2), mini(n+2);
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        maxi[x]++;
        mini[x]++;
    }
    int mx = 0, mn = 0;
    for(int i = 1; i <= n; i++){
        if(maxi[i] == 0) continue;
        if(maxi[i-1] == 0){
            maxi[i-1]++;
            maxi[i]--;
        }
        if(maxi[i] > 1){
            maxi[i+1]++;
            maxi[i]--;
        }
    }
    for(int i = 0; i <= n+1; i++){
        if(maxi[i]){
            mx++;
        }
    }
    for(int i = 1; i <= n; i++){
        if(mini[i] == 0) continue;
        mn++;
        i += 2;
    }
    cout << mn << " " << mx << "\n";
    return 0;
}
