#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution{
    public:
    int minMeetingRooms(vector<pair<int, int> > &intervals){
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int> > inRoom;
        int rooms = 0;
        for(int i = 0; i < (int)intervals.size(); i++){
            if(inRoom.empty()){
                inRoom.push(intervals[i].second);
                rooms++;
            }
            else{
                if(inRoom.top() <= intervals[i].first){
                    inRoom.pop();
                }
                else{
                    rooms++;
                }
                inRoom.push(intervals[i].second);
            }
        }
        return rooms;
    }
};

int main(){
    int n;
    cin >> n;
    vector<pair<int, int> > intervals(n);
    for(int i = 0; i < n; i++){
        cin >> intervals[i].first >> intervals[i].second;
    }
    Solution *obj = new Solution();
    int ans = obj->minMeetingRooms(intervals);
    cout << ans << "\n";
    return 0;
}
