#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        vector<int> ans(n);
        int num = n, last = 0;
        for(int i = 0; i < n; i++){
            if(i == n-1 || s[i] == '>'){
                for(int j = i; j >= last; j--){
                    ans[j] = num--;
                }
                last = i+1;
            }
        }
        for(int i = 0; i < n; i++){
            cout << ans[i] << " \n"[i == n-1];
        }
        num = 1, last = 0;
        for(int i = 0; i < n; i++){
            if(i == n-1 || s[i] == '<'){
                for(int j = i; j >= last; j--){
                    ans[j] = num++;
                }
                last = i+1;
            }
        }
        for(int i = 0; i < n; i++){
            cout << ans[i] << " \n"[i == n-1];
        }
    }
    return 0;
}
