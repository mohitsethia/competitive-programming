#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    multiset<int> s;
    int maxLength = 0, curr = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        s.insert(a[i]);
        while(*s.rbegin() - *s.begin() > 1){
            s.erase(s.find(a[curr++]));
        }
        maxLength = max(maxLength, (int)s.size());
    }
    cout << maxLength << endl;
    return 0;
}
