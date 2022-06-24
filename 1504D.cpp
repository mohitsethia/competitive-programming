#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<pair<ll, ll> > grid[2];
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= n; j++){
            grid[(i+j)%2].emplace_back(make_pair(i, j));
        }
    }
    ll AliceColor, Chosen, Column, i, j;
    for(ll k = 1; k <= n*n; k++){
        cin >> AliceColor;
        if(AliceColor == 1){
            if(!grid[1].empty()){
                Column = 1;
                Chosen = 2;
            }
            else{
                Column = 0;
                Chosen = 3;
            }
        }
        else if(AliceColor == 2){
            if(!grid[0].empty()){
                Column = 0;
                Chosen = 1;
            }
            else{
                Column = 1;
                Chosen = 3;
            }
        }
        else{
            if(!grid[0].empty()){
                Column = 0;
                Chosen = 1;
            }
            else{
                Column = 1;
                Chosen = 2;
            }
        }
        i = grid[Column].back().first;
        j = grid[Column].back().second;
        grid[Column].pop_back();
        cout << Chosen << " " << i << " " << j << endl;
    }
    return 0;
}
