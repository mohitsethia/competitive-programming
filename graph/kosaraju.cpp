#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<set>
#include<cstdio>
#include<unordered_set>
#include<stack>

using namespace std;

#define int long long

unordered_map<int, vector<int> > adj, rev;
vector<vector<int> > s;
int V, edges;

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
    for(int i = 1; i <= V; i++){
        for(int j: adj[i]){
            rev[j].push_back(i);
        }
    }
}
vector<int> p;
void DFS2(int i, vector<bool>& visited){
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
    vector<bool> visited(V+1, false);
    for(int i = 1; i <= V; i++){
        if(!visited[i]){
            DFS1(i, visited, myStack);
        }
    }
    reverse();
    visited = vector<bool> (V, false);
    while(!myStack.empty()){
        int curr = myStack.top();
        myStack.pop();
        if(visited[curr] == false){
            DFS2(curr, visited);
            s.push_back(p);
            p.clear();
        }
    }
}
int32_t main(){
    cin >> V >> edges;
    for(int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    findSCCs();
    for(int i = 0; i < s.size(); i++){
        cout << i << " --> ";
        for(int j = 0; j < s[i].size(); j++){
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
}
