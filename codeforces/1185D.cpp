#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

#define int long long

const int N = 2e5+5;

pair<int, int> a[N];
int d[N];

int32_t main(){
    int n;
    cin >> n;
    if(n <= 3){
        cout << "1\n";
        return 0;
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a+1, a+n+1);
    multiset<int> diff;
    
    for(int i = 2; i <= n; i++){
        d[i] = a[i].first-a[i-1].first;
        diff.insert(d[i]);
    }
    for(int i = 1; i <= n; i++){
        if(i == 1){
            diff.erase(diff.find(d[2]));
            if(diff.empty() || *diff.begin() == *diff.rbegin()){
                cout << a[i].second << "\n";
                exit(0);
            }
            diff.insert(d[2]);
        }
        else if(i == n){
            diff.erase(diff.find(d[n]));
            if(diff.empty() || *diff.begin() == *diff.rbegin()){
                cout << a[n].second << "\n";
                exit(0);
            }
            diff.insert(d[n]);
        }
        else{
            diff.erase(diff.find(d[i]));
            diff.erase(diff.find(d[i+1]));
            diff.insert(a[i+1].first-a[i-1].first);
            if(diff.empty() || *diff.begin() == *diff.rbegin()){
                cout << a[i].second << "\n";
                exit(0);
            }
            diff.insert(d[i]);
            diff.insert(d[i+1]);
            diff.erase(diff.find(a[i+1].first-a[i-1].first));
        }
    }
    cout << "-1\n";
    return 0;
}
