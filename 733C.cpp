#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 555;
int n, k;
int a[N], b[N];
long long pref[N] = {0};
pair<int, int> q[N];
pair<int, int> safe[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pref[i] = pref[i-1] + a[i];
        safe[i].first = safe[i].second = -1;
    }
    cin >> k;
    for(int i = 1; i <= k; i++){
        cin >> b[i];
    }
    int curr = 0;
    for(int i = 1; i <= k; i++){
        int s = curr;
        while(s <= n && pref[s]-pref[curr] < b[i]) s++;
        if(s > n || pref[s]-pref[curr] != b[i]){
            cout << "NO\n";
            return 0;
        }
        q[i] = make_pair(curr+1, s);
        curr = s;
    }
    if(curr != n){
        cout << "NO\n";
        return 0;
    }
    for(int i = k; i > 0; i--){
        int mx = 0;
        int r = q[i].second, l = q[i].first;
        if(l == r) continue;
        for(int j = l; j <= r; j++){
            mx = max(mx, a[j]);
        }
        for(int j = l; j <= r; j++){
            if(a[j] != mx) continue;
            if(j != l && a[j] != a[j-1]){
                safe[i].first = j;
                safe[i].second = 0;
                break;
            }
            if(j != r && a[j] != a[j+1]){
                safe[i].first = j;
                safe[i].second = 1;
                break;
            }
        }
        if(safe[i].first == -1){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    for(int i = k; i >= 1; i--){
        int r = q[i].second, l = q[i].first;
        if(l == r) continue;
        if(safe[i].second == 1){
            a[safe[i].first] += a[safe[i].first+1];
            cout << safe[i].first << " R\n";
            for(int j = safe[i].first+1; j < r; j++){
                a[j] = a[j+1];
            }
            r--;
        }
        else{
            a[safe[i].first-1] += a[safe[i].first];
            cout << safe[i].first << " L\n";
            for(int j = safe[i].first +1; j <= r; j++){
                a[j-1] = a[j];
            }
            r--;
            safe[i].first--;
        }
        for(int j = safe[i].first; j < r; j++){
            cout << safe[i].first << " R\n";
        }
        for(int j = safe[i].first; j > l; j--){
            cout << j << " L\n";
        }
    }
    return 0;
}
