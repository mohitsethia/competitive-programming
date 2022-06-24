#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

#define int long long

const int LCM = 232792560; // to deal with fractions as integral LCM 1 to 20

const int N = 2e5 + 1;

int32_t main(){
    int n;
    cin >> n;
    vector<vector<pair<int, int> > > contribution(21, vector<pair<int, int> >(N, {0, 0}));
    for(int i = 1; i <= 20; i++){
        for(int j = 1; j <= N; j++) contribution[i][j].second = j;
    }
    for(int i = 1; i <= n; i++){
        int m, k;
        cin >> m >> k;
        for(int j = 1; j <= k; j++){
            contribution[j][m].first += LCM;
        }
        for(int j = k+1; j <= 20; j++){
            contribution[j][m].first += (LCM/j)*k;
        }
    }
    int ans = -1;
    int idx = -1;
    for(int i = 1; i <= 20; i++){
        sort(contribution[i].begin()+1, contribution[i].end());
        reverse(contribution[i].begin()+1, contribution[i].end());
        int curr_max =0;
        for(int j = 1; j <= i; j++){
            curr_max += contribution[i][j].first;
        }
        if(curr_max >= ans){
            ans = curr_max;
            idx = i;
        }
    }
    cout << idx << "\n";
    for(int i = 1; i <= idx; i++){
        cout << contribution[idx][i].second << " ";
    }
    return 0;
}
