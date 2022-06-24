#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        set<int> inPlace;
        multiset<int> toBePlaced;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            if(x <= n){
                if(inPlace.count(x)) toBePlaced.insert(x);
                else inPlace.insert(x);
            }
            else{
                toBePlaced.insert(x);
            }
        }
        int res = 0;
        for(int i = 1; i <= n; i++){
            if(inPlace.count(i)) continue;
            int beg = *toBePlaced.begin();
            if(beg < i){
                res = -1;
                break;
            }
            toBePlaced.erase(toBePlaced.begin());
            int k = beg-i;
            if(beg%k != i){
                res = -1;
                break;
            }
            res++;
        }
        cout << res << "\n";
    }
    return 0;
}
