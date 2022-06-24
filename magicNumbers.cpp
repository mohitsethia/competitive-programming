#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<numeric>
#include<iomanip>
#include<cmath>
using namespace std;
using ll = long long;
#define vi vector<ll>
#define vb vector<bool>
#define pi pair<ll, ll>
#define pb push_back
#define mk make_pair
#define eb emplace_back
const ll mod = (ll)1e9 + 7ll;
string convertToString(int n){
    string p = "";
    while(n){
        p += ((n%10)+'0');
        n /= 10;
    }
    reverse(p.begin(), p.end());
    return p;
}
bool check(int n){
    string s = to_string(n);
    int len = s.length();
    vb visited(len+1, false);
    int vis = 0;
    int i = 0;
    int pos = i;
    while(vis < len){
        if(visited[i]){
            return false;
        }
        else{
            vis++;
            visited[i] = true;
            pos = s[pos]-'0';
            pos += i;
            i = pos%len;
            pos = i;
        }
    }
    return pos == 0;
}
bool isDuplicate(int n){
    vb visited(10, false);
    while(n > 0){
        int r = n%10;
        if(visited[r]){
            return true;
        }
        visited[r] = true;
        n /= 10;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int l, r;
    cin >> l >> r;
    vi res;
    for(int i = l; i <= r; i++){
        if(!isDuplicate(i) && check(i)){
            res.eb(i);
        }
    }
    if((ll)res.size() == 0){
        cout << "-1\n";
    }
    else{
        for(ll &it: res){
            cout << it << "\n";
        }
    }
    return 0;
}
