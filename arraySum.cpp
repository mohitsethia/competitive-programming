#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a;
        int x;
        for(int i = 0; i < n; i++){
            cin >> x;
            if(a.empty()){
                a.push_back(x);
            }
            else if(a.back() != x){
                a.push_back(x);
            }
        }
        if(k == 1 && a.size() > 1){
            cout << "-1\n";
        }
        else if(k >= a.size()){
            cout << "1\n";
        }
        else{
            cout << ceil((a.size()-1)*1.0/(k-1)) << endl;
        }
    }
    return 0;
}
