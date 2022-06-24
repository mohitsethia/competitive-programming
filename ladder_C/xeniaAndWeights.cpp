#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
#define int long long
int ones[11];
int ans[1005] = {0};
int m;
bool dfs(int sum1, int sum2, int cnt, int pre){
    if(cnt >= m){
        return true;
    }
    for(int i = 1; i <= 10; i++){
        if(ones[i] && i != pre){
            if(cnt%2 == 0){
                if(sum1 + i > sum2){
                    if(dfs(sum1+i, sum2, cnt+1, i)){
                        ans[cnt] = i;
                        return true;
                    }
                }
            }
            else{
                if(sum2+i > sum1){
                    if(dfs(sum1, sum2+i, cnt+1, i)){
                        ans[cnt] = i;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
int32_t main(){
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '1') ones[i+1] = 1;
        else ones[i+1] = 0;
    }
    cin >> m;
    if(!dfs(0, 0, 0, -1)){
        cout << "NO";
    }
    else{
        cout << "YES" << endl;
        for(int i = 0; i < m; i++){
            cout << ans[i] << " ";
        }
    }
    cout << endl;
    return 0;
}
