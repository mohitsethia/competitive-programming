#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, k;
    cin >> n >> k;
    cout << 'a';
    n--;
    vector<char> v;
    v.emplace_back('a');
    for(ll i = 1; i < k; i++){
        if(n){
            cout << (char)('a'+i);
            n--;
            v.emplace_back('a'+i);
        }
        else{
            return 0;
        }
        for(ll j = i+1; j < k; j++){
            if(n){
                cout << char('a'+j);
                n--;
                v.emplace_back('a'+j);
            }
            else{
                return 0;
            }
            if(n){
                cout << (char)('a'+i);
                n--;
                v.emplace_back('a'+i);
            }
            else{
                return 0;
            }
        }
        if(n){
            cout << char('a'+i);
            n--;
            v.emplace_back('a'+i);
        }
        else{
            return 0;
        }
        if(n){
            cout << char('a');
            n--;
            v.emplace_back('a');
        }
        else{
            return 0;
        }
    }
    ll i = 0;
    while(n){
        n--;
        cout << v[i];
        i++;
        i = i%(ll)v.size();
    }
    return 0;
}
