#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> cnt[6];
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            for(int j = 0; j < 6; j++){
                cnt[j].push_back(-(int)s.length());
            }
            for(auto c: s){
                cnt[c - 'a'].back() += 2;
            }
        }
        int best = 0;
        for(int i = 0; i < 6; i++){
            sort(cnt[i].begin(), cnt[i].end(), greater<int>());
            if(cnt[i][0] <= 0) continue;
            int sum = cnt[i][0];
            int j = 1;
            for(; j < n && sum > 0; j++){
                sum += cnt[i][j];
            }
            if(sum <= 0) j--;
            best = max(best, j);
        }
        cout << best << "\n";
    }
    return 0;
}

// 6
// 3
// bac
// aaada
// e
// 3
// aba
// abcde
// aba
// 2
// baba
// baba
// 4
// ab
// ab
// c
// bc
// 5
// cbdca
// d
// a
// d
// e
// 3
// b
// c
// ca

