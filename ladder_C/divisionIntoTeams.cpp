#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
#define int long long
typedef pair<int, int> pi;
typedef vector<pi> vi;
void print_ans(vector<int>& a){
    cout << (int)a.size() << endl;
    for(int i = 0; i < (int)a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i+1;
    }
    sort(a.begin(), a.end());
    vector<int> p, q;
    for(int i = 0; i < n; i++){
        if(i%2){
            q.push_back(a[i].second);
        }
        else{
            p.push_back(a[i].second);
        }
    }
    print_ans(p);
    print_ans(q);
    return 0;
}
