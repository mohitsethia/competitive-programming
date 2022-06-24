#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    unordered_map<int, set<int> > mp;
    for(int i = 0; i < n; i++){
        if(mp.find(a[i]) == mp.end() || (int)mp[a[i]].size() == 0){
            mp[a[i]].insert(i);
        }
        else{
            auto idxx = mp[a[i]].begin();
            int index = *idxx;
            mp[a[i]].erase(idxx);
            a[index] += k;
            mp[a[index]].insert(index);
            mp[a[i]].insert(i);
        }
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << " \n"[i == n-1];
    }
    return 0;
}
