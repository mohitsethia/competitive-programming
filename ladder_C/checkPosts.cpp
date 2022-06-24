#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<unordered_map>
#include<stack>
#include<climits>

using namespace std;
#define int long long
#define mod 1000000007

unordered_map<int, vector<int> > rev, adj;
vector<vector<int> > s;
int n, edges;
vector<int> cost;

void DFS1(int i, vector<bool>& visited, stack<int>& myStack){
    visited[i] = true;
    for(int j: adj[i]){
        if(!visited[j]){
            DFS1(j, visited, myStack);
        }
    }
    myStack.push(i);
}

void reverse(){
    for(int i = 1; i <= n; i++){
        for(int j: adj[i]){
            rev[j].push_back(i);
        }
    }
}
vector<int> p;
void DFS2(int i, vector<bool>&  visited){
    p.push_back(i);
    visited[i] = true;
    for(int j: rev[i]){
        if(!visited[j]){
            DFS2(j, visited);
        }
    }
}

void findSCCs(){
    stack<int> myStack;
    vector<bool> visited(n+1, false);
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            DFS1(i, visited, myStack);
        }
    }
    visited = vector<bool>(n+1, false);
    reverse();
    while(!myStack.empty()){
        int curr = myStack.top();
        myStack.pop();
        if(!visited[curr]){
            DFS2(curr, visited);
            s.push_back(p);
            p.clear();
        }
    }
    vector<vector<int> > fake(s.size());
    vector<int> numberOfWays(s.size(), 1);
    int minCost = 0;
    for(int i = 0; i < (int)s.size(); i++){
        for(int j = 0; j < (int)s[i].size(); j++){
            fake[i].push_back(cost[s[i][j]]);
        }
        sort(fake[i].begin(), fake[i].end());
        minCost += fake[i][0];
        for(int j = 1; j < (int)fake[i].size(); j++){
            if(fake[i][j] == fake[i][j-1]){
                numberOfWays[i]++;
            }
            else{
                break;
            }
        }
    }
    int total_ways = 1;
    for(int i = 0; i < (int)numberOfWays.size(); i++){
        total_ways *= numberOfWays[i];
        total_ways %= mod;
    }
    cout << minCost << " " << total_ways << endl;
}

int32_t main(){
    cin >> n;
    cost = vector<int>(n+1);
    for(int i = 1; i <= n; i++){
        cin >> cost[i];
    }
    cin >> edges;
    for(int i = 1; i <= edges; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    findSCCs();
}
