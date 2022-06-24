#include<iostream>
#include<climits>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, ans = 0, count = 0, exp = 0;
        cin >> n;
        vector<pair<int, int> > v;
        while(n > 0){
            int x = n%10;
            if(x != 0){
                v.push_back(make_pair(x, count));
            }
            count++;
            n /= 10;
        }
        ans = v.size();
        cout << ans << endl;
        for(auto it : v){
            cout << it.first * pow(10, it.second) << " ";
        }
        cout << endl;
    }
    return 0;
}
