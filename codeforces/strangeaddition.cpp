#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    int cnt[5] = {0};
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a == 0){
            cnt[0] = 1;
            continue;
        }
        if(a == 100){
            cnt[1] = 1;
            continue;
        }
        if(a%10 == 0){
            cnt[2] = a;
            continue;
        }
        if(a < 10){
            cnt[3] = a;
            continue;
        }
        cnt[4] = a;
    }
    vector<int> ans;
    if(cnt[0]) ans.push_back(0);
    if(cnt[1]) ans.push_back(100);
    if(cnt[2]) ans.push_back(cnt[2]);
    if(cnt[3]) ans.push_back(cnt[3]);
    if(!cnt[2] && !cnt[3] && cnt[4]) ans.push_back(cnt[4]);
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }   
    return 0;
}