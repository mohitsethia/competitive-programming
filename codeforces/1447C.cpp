#include<iostream>
#include<algorithm>
#include<vector>

#define int long long

using namespace std;

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,w;
        cin >> n >> w;
        vector<pair<int, int> > a(n);
        int sum = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i].first;
            sum += a[i].first;
            a[i].second = i;
        }
        if(sum >= (w+1)/2 && sum <= w){
            cout << n << "\n";
            for(int i = 0; i < n; i++){
                cout << i+1 << " ";
            }
            cout << "\n";
            continue;
        }
        else if(sum < (w+1)/2){
            cout << "-1\n";
            continue;
        }
        sort(a.begin(), a.end());
        int i = 0, j = 0;
        sum = 0;
        bool found = false;
        while(i < n && j <= n){
            if(sum > w){
                sum -= a[i].first;
                i++;
            }
            else if(sum < (w+1)/2){
                sum += a[j].first;
                j++;
            }
            else if(sum >= (w+1)/2 && sum <= w){
                cout << j-i << "\n";
                for(int k = i; k < j; k++){
                    cout << a[k].second+1 << " ";
                }
                found = true;
                break;
            }
        }
        if(!found) cout << "-1\n";
    }
    return 0;
}
