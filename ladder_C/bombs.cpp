#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
#define int long long
bool myComparator(pair<int, int> a, pair<int, int> b){
    if(abs(a.first) > abs(b.first)) return false;
    else if(abs(a.first) < abs(b.first)) return true;
    else{
        if(abs(a.second) > abs(b.second)) return false;
        else return true;
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> points[i].first >> points[i].second;
        if(points[i].first == 0 || points[i].second == 0){
            ans += 4;
        }
        else{
            ans += 6;
        }
    }
    sort(points.begin(), points.end(), myComparator);
    cout << ans << endl;
    for(int i = 0 ; i < n; i++){
        if(points[i].first == 0 || points[i].second == 0){
            if(points[i].first == 0){
                if(points[i].second > 0){
                    cout << "1 " << points[i].second << " U\n";
                }
                else{
                    cout << "1 " << abs(points[i].second) << " D\n";
                }
                cout << "2\n";
                if(points[i].second > 0){
                    cout << "1 " << points[i].second << " D\n";
                }
                else{
                    cout << "1 " << abs(points[i].second) << " U\n";
                }
                cout << "3\n";
            }
            else if(points[i].second == 0){
                if(points[i].first > 0){
                    cout << "1 " << points[i].first << " R\n";
                }
                else{
                    cout << "1 " << abs(points[i].first) << " L\n";
                }
                cout << "2\n";
                if(points[i].first > 0){
                    cout << "1 " << points[i].first << " L\n";
                }
                else{
                    cout << "1 " << abs(points[i].first) << " R\n";
                }
                cout << "3\n";
            }
        }
        else{
            if(points[i].first > 0){
                cout << "1 " << points[i].first << " R\n";
            }
            else{
                cout << "1 " << abs(points[i].first) << " L\n";
            }
            if(points[i].second > 0){
                cout << "1 " << points[i].second << " U\n";
            }
            else{
                cout << "1 " << abs(points[i].second) << " D\n";
            }
            cout << "2\n";
            if(points[i].first > 0){
                cout << "1 " << points[i].first << " L\n";
            }
            else{
                cout << "1 " << abs(points[i].first) << " R\n";
            }
            if(points[i].second > 0){
                cout << "1 " << points[i].second << " D\n";
            }
            else{
                cout << "1 " << abs(points[i].second) << " U\n";
            }
            cout << "3\n";
        }
    }
    return 0;
}
