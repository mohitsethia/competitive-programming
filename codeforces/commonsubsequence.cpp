#include<iostream>
#include<map>
#include<set>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        set<int> freq;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            freq.insert(a[i]);
        }
        int id = 0;
        for(int i = 0; i < m; i++){
            cin >> b[i];
            if(freq.find(b[i]) != freq.end()){
                id = b[i];
            }
        }
        if(!id){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            cout << "1 " << id << endl;
        }
    }
    return 0;
}
