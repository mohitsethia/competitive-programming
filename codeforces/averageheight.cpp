#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> even;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            if(x%2)
                cout << x << " ";
            else
                even.push_back(x);
        }
        for(int& e: even){
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}
