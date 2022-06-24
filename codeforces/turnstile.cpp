#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
vector<int> getTimeStamps(vector<int> time, vector<int> dir) {
    int n = time.size();
    time.push_back(1e9 + 1e6);
    vector<int> out(n);
    queue<int> q[2]; // enter(0), exit(1)
    for (int i = 0, t = time[0], fl = -1; i < n; i++) {
        q[dir[i]].push(i);
        while (t < time[i + 1]) {
            if (!q[0].empty() && !fl){
                out[q[0].front()] = t++;
                q[0].pop();
                fl = 0;
            }
            else if (!q[1].empty()){
                out[q[1].front()] = t++;
                q[1].pop();
                fl = 1;
            }
            else if (!q[0].empty()) {
                out[q[0].front()] = t++;
                q[0].pop();
                fl = 0;
            }
            else {
                t = time[i + 1];
                fl = -1;
            }
        }
    }
    return out;
}

int main(){
    int n;
    cin >> n;
    vector<int> time(n), dir(n);
    for(int i = 0; i < n; i++){
        cin >> time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> dir[i];
    }
    vector<int> ans = getTimeStamps(time, dir);
    for(auto it: ans){
        cout << it << " ";
    }
    return 0;
}
