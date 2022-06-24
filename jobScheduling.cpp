#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution{
    int findLastIndex(vector<pair<int, pair<int, int> > > &jobs, int idx){
        int l = 0, r = (int)jobs.size()-1;
        int ans = -1;
        while(l <= r){
            int mid = (l+r)>>1;
            if(jobs[mid].first <= jobs[idx].second.first){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return ans;
    }

public:

    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit){
        int n = startTime.size();
        vector<pair<int, pair<int, int> > > jobs(n);
        for(int i = 0; i < n; i++){
            jobs[i].first = endTime[i];
            jobs[i].second.first = startTime[i];
            jobs[i].second.second = profit[i];
        }
        sort(jobs.begin(), jobs.end());
        vector<int> profitTillNow(n);
        profitTillNow[0] = jobs[0].second.second;
        for(int i = 1; i < n; i++){
            int idx = findLastIndex(jobs, i);
            int inclusive = jobs[i].second.second;
            if(idx != -1){
                inclusive += profitTillNow[idx];
            }
            profitTillNow[i] = max(inclusive, profitTillNow[i-1]);
        }
        return profitTillNow[n-1];
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> startTime(n), endTime(n), profit(n);
    for(int i = 0; i < n; i++){
        cin >> startTime[i];
    }
    for(int i = 0; i < n; i++){
        cin >> endTime[i];
    }
    for(int i = 0; i < n; i++){
        cin >> profit[i];
    }
    Solution *obj = new Solution();
    cout << obj->jobScheduling(startTime, endTime, profit) << "\n";
    return 0;
}
