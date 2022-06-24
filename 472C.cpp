#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct query{
    string ff, ss;
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    query a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i].ff >> a[i].ss;
    }
    int p[n];
    for(int i = 0; i < n; i++){
        cin >> p[i];
        p[i]--;
    }
    string last = "";
    last = min(a[p[0]].ff, a[p[0]].ss);
    for(int i = 1; i < n; i++){
        string s2 = a[p[i]].ff;
        string t2 = a[p[i]].ss;
        if(last >= s2 && last >= t2){
            cout << "NO\n";
            return 0;
        }
        if(last < s2 && last < t2){
            last = min(s2, t2);
        }
        else if(last < s2){
            last = s2;
        }
        else{
            last = t2;
        }
    }
    cout << "YES\n";
    return 0;
}
