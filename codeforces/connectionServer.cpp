#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int findPar(int x, vector<int> &par){
    if(par[x] == x) return x;
    return par[x] = findPar(par[x], par);
}

void merge(int x, int y, vector<int> &par){
    int sy = findPar(y, par);
    par[x] = sy;
}

vector<vector<int> > findMinCost(int n, vector<vector<int> > &connections){
    vector<int> par(n+1);
    for(int i = 0; i <= n; i++){
        par[i] = i;
    }
    sort(connections.begin(), connections.end(), [&](const vector<int> &a, const vector<int> &b){
        return a[2] < b[2];
    });
    vector<vector<int> > ans;
    for(int i = 0; i < n; i++){
        int sx = findPar(connections[i][0], par);
        int sy = findPar(connections[i][1], par);
        if(sx != sy){
            merge(connections[i][0], connections[i][1], par);
            ans.push_back(connections[i]);
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int> > connection;
    for(int i = 0; i < n; i++){
        int u, v, cost;
        cin >> u >> v >> cost;
        connection.push_back({u, v, cost});
    }
    vector<vector<int> > res = findMinCost(n, connection);
    for(auto it: res){
        for(auto v: it){
            cout << v << " ";
        }
        cout << "\n";
    }
    return 0;
}
