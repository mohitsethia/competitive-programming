#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int l[m];
    long long s = 0;
    for(int i = 0; i < m; i++){
        cin >> l[i];
        s += l[i];
    }
    if(s < n){
        cout << "-1\n";
    }
    else{
        vector<int> p;
        for(int i = 0; i < m; i++){
            p.emplace_back(i+1);
        }
        for(int i = 0; i < m; i++){
            if(p[i] + l[i]-1 > n){
                cout << "-1\n";
                return 0;
            }
        }
        p[m-1] = n-l[m-1]+1;
        for(int i = m-2; i >= 0; i--){
            if(p[i]+l[i] < p[i+1]){
                p[i] = p[i+1]-l[i];
            }
        }
        for(int  i = 0; i < m; i++){
            cout << p[i] << " \n"[i == m-1];
        }
    }
    return 0;
}
