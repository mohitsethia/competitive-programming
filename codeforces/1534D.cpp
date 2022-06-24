#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<numeric>
#include<climits>
#include<cmath>
using namespace std;
using ll = long long;
vector<int> query(int i, int n){
    vector<int> res(n+1);
    cout << "? " << i << endl;
    cout.flush();
    for(int i = 1; i <= n; i++){
        cin >> res[i];
    }
    return res;
}
void solve(int n){
    vector<int> graph[n+1];
    vector<int> res1 = query(1, n);
    int odd = 0, even = 0;
    for(int i = 1; i <= n; i++){
        if(res1[i] == 1){
            graph[i].push_back(1);
        }
        if(res1[i]%2){
            odd++;
        }
        else{
            even++;
        }
    }
    if(odd < even){
        for(int i = 2; i <= n; i++){
            if(res1[i]%2){
                vector<int> res = query(i, n);
                for(int j = 2; j <= n; j++){
                    if(res[j] == 1){
                        graph[j].push_back(i);
                    }
                }
            }
        }
    }
    else{
        for(int i = 2; i <= n; i++){
            if(res1[i]%2 == 0){
                vector<int> res = query(i, n);
                for(int j = 2; j <= n; j++){
                    if(res[j] == 1){
                        graph[j].push_back(i);
                    }
                }
            }
        }
    }
    cout << "!" << endl;
    cout.flush();
    for(int i = 1; i <= n; i++){
        if(graph[i].size() > 0){
            for(auto it: graph[i]){
                cout << i << " " << it << endl;
                cout.flush();
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    solve(n);
}
