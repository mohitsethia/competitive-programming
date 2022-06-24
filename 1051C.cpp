#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(101, 0);
    vector<int> b(n);
    int x;
    for(int i = 0; i < n; i++){
        cin >> b[i];
        a[b[i]]++;
    }
    set<int> st[2];
    int toggle = 0;
    for(int i = 1; i <= 100; i++){
        if(a[i] == 1){
            if(toggle){
                st[toggle].insert(i);
            }
            else{
                st[toggle].insert(i);
            }
            toggle = 1-toggle;
        }
    }
    int sz1 = st[0].size();
    int sz2 = st[1].size();
    if(sz1 == sz2){
        cout << "YES\n";
        string res(n, 'A');
        for(int i = 0; i < n; i++){
            if(st[1].count(b[i])){
                res[i] = 'B';
            }
        }
        cout << res;
        cout << "\n";
    }
    else{
        string res(n, 'A');
        for(int i = 0; i < n; i++){
            if(st[1].count(b[i])){
                res[i] = 'B';
            }
        }
        int id = -1;
        for(int i = 1; i <= 100; i++){
            if(a[i] >= 3){
                id = i;
                break;
            }
        }
        if(id == -1){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
            bool done = false;
            for(int i = 0; i < n; i++){
                if(!done){
                    if(b[i] == id){
                        res[i] = 'B';
                        done = true;
                    }
                }
            }
            cout << res << "\n";
        }
    }
    return 0;
}
