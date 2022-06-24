#include<iostream>
#include<algorithm>
#include<assert.h>

using namespace std;

bool is_sorted(vector<int> &a){
    for(int i = 1; i < (int)a.size(); i++){
        if(a[i] < a[i-1]) return false;
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        vector<int> res;
        while(true){
            if(is_sorted(a)){
                break;
            }
            vector<int> b(n+1);
            for(int i = 0; i < n; i++){
                b[a[i]]++;
            }
            int mex = n;
            for(int i = 0; i <= n; i++){
                if(!b[i]){
                    mex = i;
                    break;
                }
            }
            if(mex == n){
                bool bad = false;
                for(int i = 0; i < n-1; i++){
                    if(a[i] > a[i+1]) bad = true;
                }
                if(!bad) break;
                for(int i = 0; i < n; i++){
                    if(a[i] != i){
                        res.push_back(i+1);
                        a[i] = mex;
                        break;
                    }
                }
            }
            else{
                res.push_back(mex+1);
                a[mex] = mex;
            }
        }
        cout << res.size() << "\n";
        for(int i : res){
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
