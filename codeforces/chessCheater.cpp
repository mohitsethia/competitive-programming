#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        ll wins = 0, losses = 0, winning_streak = 0;
        vector<int> losing_streak;
        for(int i = 0; i < n; i++){
            if(s[i] == 'W'){
                wins++;
                if(i == 0 || s[i-1] == 'L') winning_streak++;
            }
            if(s[i] == 'L'){
                losses++;
                if(i == 0 || s[i-1] == 'W') losing_streak.push_back(0);
                losing_streak.back()++;
            }
        }
        if(k >= losses){
            cout << 2*n-1 << endl;
            continue;
        }
        if(wins == 0){
            if(k == 0) cout << 0 << endl;
            else{
                cout << 2*k-1 << endl;
            }
            continue;
        }
        if(s[0] == 'L') losing_streak[0] = 1e8;
        if(s[n-1] == 'L') losing_streak.back() = 1e8;
        sort(losing_streak.begin(), losing_streak.end());
        wins += k;
        for(int loss: losing_streak){
            if(loss > k) break;
            else{
                k -= loss;
                winning_streak--;
            }
        }
        cout << 2*wins - winning_streak << endl;
    }
    return 0;
}
