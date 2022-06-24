#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

#define int long long
#define pb push_back

using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    map<int, int> freq;
    map<pair<int, int>, vector<int> > pairing;
    int x, y, z;
    for(int i = 0; i < n-2; i++){
        cin >> x >> y >> z;
        freq[x]++, freq[y]++, freq[z]++;
        pairing[{x, y}].pb(z);
        pairing[{y, x}].pb(z);
        pairing[{x, z}].pb(y);
        pairing[{z, x}].pb(y);
        pairing[{y, z}].pb(x);
        pairing[{z, y}].pb(x);
    }
    for(auto a: freq){
        if(a.second == 1){
            x = a.first;
            break;
        }
    }
    cout << x << " ";
    for(auto a: pairing){
        if(a.first.first == x && freq[a.first.second] == 2){
            y = a.first.second;
            break;
        }
    }
    cout << y << " ";
    vector<bool> vis(n+1, false);
    vis[x] = true;
    vis[y] = true;
    for(int i = 0; i < n-2; i++){
        for(auto a: pairing[{x, y}]){
            if(!vis[a]){
                vis[a] = true;
                cout << a << " ";
                z = a;
                break;
            }
        }
        x = y;
        y = z;
    }
    cout << "\n";
    return 0;
}
