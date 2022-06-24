#include<iostream>
#include<algorithm>
#include<vector>
#define int long long

using namespace std;
int warriorSelection(int M, vector<int> strength, vector<int> speed, vector<int> tactic){
    vector<int> ans;
    int N = strength.size();
    for(int i = 0; i < N; i++){
        int k = abs(strength[i]+speed[i]+tactic[i]);
        ans.push_back(k);
    }
    sort(ans.begin(), ans.end(), greater<int>());
    int res = 0;
    for(int i = 0; i < M; i++){
        res += ans[i];
    }
    return res;
}
int32_t main(){
    int N, M;
    cin >> N >> M;
    vector<int> strength(N), speed(N), tactic(N);
    for(int i = 0; i < N; i++){
        cin >> strength[i];
    }
    for(int i = 0; i < N; i++){
        cin >> speed[i];
    }
    for(int i = 0; i < N; i++){
        cin >> tactic[i];
    }
    int result;
    result = warriorSelection(M, strength, speed, tactic);
    cout << result;
    return 0;
}
