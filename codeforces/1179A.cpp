#include<iostream>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

#define int long long

int32_t main(){
    int n, q;
    cin >> n >> q;
    deque<int> dq;
    int mx = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        dq.push_back(a);
        mx = max(mx, a);
    }
    int maxIndex = 0;
    map<int, pair<int, int>> mp;
    while(true){
        int first = dq.front();
        dq.pop_front();
        int second = dq.front();
        dq.pop_front();
        if(first == mx){
            dq.push_front(second);
            dq.push_front(first);
            break;
        }
        maxIndex++;
        mp[maxIndex] = {first, second};
        if(second > first){
            swap(first, second);
        }
        dq.push_front(first);
        dq.push_back(second);
    }
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        a[i] = dq.front();
        dq.pop_front();
    }
    for(int i = 0; i < q; i++){
        int m;
        cin >> m;
        if(m <= maxIndex){
            cout << mp[m].first << " " << mp[m].second << "\n";
        }
        else{
            cout << mx << " " << a[(m - (maxIndex+1)) % (n-1)+1] << "\n";
        }
    }
    return 0;
}
