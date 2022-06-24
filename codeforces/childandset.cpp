#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int main(){
    int sum, limit;
    scanf("%d%d", &sum, &limit);
    vector<vector<int> > v;
    for(int i = limit; i >= 1; i--){
        for(int j = 0; j <= 19; j++){
            if(((1<<j)&i) == (1<<j) and (1<<j) <= sum){
                v.push_back({(1<<j), i});
                break;
            }
        }
    }
    sort(v.rbegin(), v.rend());
    vector<int> ans;
    for(vector<int> &i: v){
        if(i[0] <= sum){
            ans.push_back(i[1]);
            sum -= i[0];
        }
    }
    if(sum){
        cout << "-1\n";
        return 0;
    }
    cout << ans.size() << endl;
    for(int& i: ans){
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
