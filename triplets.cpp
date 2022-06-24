/*
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<climits>
#include<map>
using namespace std;
int consecutive_first(vector<int>& a){
    int n = a.size();
    map<int, int> count;
    for(int i = 0; i < a.size(); i++){
        count[i]++;
    }
    vector<bool> visited(n, false);
    int cnt = 0;
    for(int i = 0; i < a.size()-3; i++){
        if(count[a[i]] && count.count(a[i]+1) && count.count(a[i]+2)){
            if(count[a[i]+1] > 0 && count[a[i]+2] > 0){
                cnt++;
                count[a[i]]--;
                count[a[i+1]]--;
                count[a[i+2]]--;
            }
        }
    }
    for(auto it: count){
        cnt += it.second/3;
    }
    return cnt;
}
int same_first(vector<int>& a){
    int n = a.size();
    map<int, int> count;
    for(int i = 0; i < a.size(); i++){
        count[i]++;
    }
    int cnt = 0;
    vector<bool> visited(n, false);
    for(auto& it: count){
        cnt += it.second/3;
        it.second = it.second-it.second/3;
    }
    for(int i = 0; i < a.size(); i++){
        if(count[a[i]] > 0 && count.count(a[i]+1) && count.count(a[i]+2)){
            if(count[a[i]+1] > 0 && count[a[i]+2] > 0){
                cnt++;
                count[a[i]]--, count[a[i]+1]--, count[a[i]+2]--;
            }
        }
    }
    return cnt;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int& i: a){
        cin >> i;
    }
    sort(a.begin(), a.end());
    int cnt1 = consecutive_first(a);
    int cnt2 = same_first(a);
    cout << max(cnt1, cnt2) << endl;
    return 0;
}
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<climits>
#include<map>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    map<int, int> count;
    for(int& i: a){
        cin >> i;
        count[i]++;
    }
    sort(a.begin(), a.end());
    int cnt = 0;
    vector<bool> visited(n, false);
    for(int i = 0; i < a.size()-3; i++){
        if(count[a[i]] && count.count(a[i]+1) && count.count(a[i]+2)){
            if(count[a[i]+1] > 0 && count[a[i]+2] > 0){
                cnt++;
                count[a[i]]--;
                count[a[i]+1]--;
                count[a[i]+2]--;
                visited[i] = visited[i+1] = visited[i+2] = true;
            }
        }
    }
    for(auto it: count){
        cnt += it.second/3;
    }
    cout << cnt << endl;
    return 0;
}
