#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n], k, j;
        vector<int> v;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            int count = 0;
            for(j = i; j < n-1; j++){
                if(abs(a[j]-a[j+1]) <= 2){
                    count++;
                    k = j;
                }
                else{
                    i = j;
                    break;
                }
            }
            v.push_back(count+1);
            if(i != j){
                i = j;
            }
        }
        int mx = v[0], mn = v[0];
        for(auto it:v){
            if(it < mn){
                mn = it;
            }
            if(it > mx){
                mx = it;
            }
        }
        cout << mn << " " << mx << endl;
    }
    return 0;
}
