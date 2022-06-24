#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

#define int long long

int32_t main(){
    int n, k;
    cin >> n >> k;
    vector<pair<int, int> > a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].second >> a[i].first;
    }
    sort(a.begin(), a.end(), greater<pair<int, int> >());
    priority_queue<int, vector<int>, greater<int> > pq;
    int curr_sum = 0, mxAns = 0;
    for(int i = 0; i < n; i++){
        int ln = pq.size();
        if(ln < k){
            pq.push(a[i].second);
            curr_sum += a[i].second;
            mxAns = max(mxAns, curr_sum * a[i].first);
        }
        else{
            if(a[i].second > pq.top()){
                int old = pq.top();
                pq.pop();
                pq.push(a[i].second);
                curr_sum -= old;
                curr_sum += a[i].second;
                mxAns = max(mxAns, curr_sum * a[i].first);
            }
        }
    }
    cout << mxAns << "\n";
    return 0;
}
