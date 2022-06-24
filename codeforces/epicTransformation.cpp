#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        map<ll, ll> mp;
        for(int i = 0; i < n; i++){
            ll x;
            cin >> x;
            mp[x]++;
        }
        priority_queue<ll> pq;
        for(auto it: mp){
            pq.push(it.second);
        }
        while(pq.size() > 1){
            ll x = pq.top();
            pq.pop();
            ll y = pq.top();
            pq.pop();
            x--, y--;
            if(x){
                pq.push(x);
            }
            if(y){
                pq.push(y);
            }
        }
        cout << (pq.size() == 0 ? 0 : pq.top()) << endl;





        /*
        vector<ll> freq;
        for(auto it: mp){
            freq.push_back(it.second);
        }
        sort(freq.begin(), freq.end());
        while(freq.size() > 1){
            ll x = freq.size()-1;
            ll y = freq.size()-2;
            if(freq[x] == freq[y]){
                freq.pop_back();
                freq.pop_back();
            }
            else if(freq[x] > freq[y]){
                freq[x] -= freq[y];
                ll temp = freq[x];
                freq.pop_back();
                freq.pop_back();
                freq.push_back(temp);
            }
            else{
                freq[y] -= freq[x];
                freq.pop_back();
            }
        }
        cout << (freq.size() == 0 ? 0 : freq[0]) << endl;
        */
    }
    return 0;
}
