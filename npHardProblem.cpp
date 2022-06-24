#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;
vector<vector<int> > graph;
vector<int> color, visit;
int count0 = 0, count1 = 0, flag = 0;
void dfs(int src, int c){
    if(flag){
        return;
    }
    if(c == 0){
        count0++;
    }
    else{
        count1++;
    }
    color[src] = c;
    visit[src] = 1;
    for(int j = 0; j < graph[src].size(); j++){
        if(visit[graph[src][j]] && color[graph[src][j]] == c){
            flag = 1;
            return;
        }
        if(!visit[graph[src][j]])
            dfs(graph[src][j], !c);
    }
}
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    graph.resize(n+1);
    color.resize(n+1, -1);
    visit.resize(n+1, 0);
    int x, y;
    for(int i = 0; i < m; i++){
        scanf("%d%d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        if(flag){
            printf("-1\n");
            return 0;
        }
        if(!visit[i]){
            dfs(i, 0);
        }
    }
    printf("%d\n", count0);
    for(int i = 1; i <= n; i++){
        if(color[i] == 0)
            printf("%d ", i);
    }
    printf("\n%d\n", count1);
    for(int i = 1; i <= n; i++){
        if(color[i] == 1)
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}
