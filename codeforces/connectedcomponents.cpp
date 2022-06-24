#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<vector>
using namespace std;
template<typename T>
class graph{
    map<T, list<T> > l;
    public:
        void addEdge(int x, int y){
            l[x].push_back(y);
            l[y].push_back(x);
        }
        void dfs_helper(T src, map<T, bool> &visited){
            cout << src << " ";
            visited[src] = true;
            for(auto p : l[src]){
                if(!visited[p]){
                    dfs_helper(p, visited);
                }
            }
        }
        void dfs(T src){
            map<T, bool> visited;
            for(auto p : l){
                T node = p.first;
                visited[node] = false;
            }
            int cnt = 0;
            for(auto p : l){
                T node = p.first;
                if(!visited[node]){
                    cout << "Component " << cnt << "-->";
                    cnt++;
                    dfs_helper(node, visited);
                    cout << endl;
                }
            }
        }
};
int main(){
    graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    g.addEdge(0, 4);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(8, 8);
    g.dfs(0);
    return 0;
}
