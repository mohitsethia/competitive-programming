#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<climits>
using namespace std;
template<typename T>
class graph{
    map<T, list<T> > l;
    public:
        void addEdge(T x, T y){
            l[x].push_back(y);
            l[y].push_back(x);
        }
//shortest path
        void bfs(T src){
            map<T, int> dist;
            queue<T> q;
            for(auto node_pair:l){
                T node = node_pair.first;
                dist[node] = INT_MAX;
            } 
            q.push(src);
            dist[src] = 0;
            while(!q.empty()){
                T node = q.front();
                q.pop();
                for(auto it:l[node]){
                    if(dist[it] == INT_MAX){
                        q.push(it);
                        dist[it] = dist[node]+1;
                        //cout << node << " " << dist[it] << endl;
                    }
                }
            }
            for(auto it:l){
                T node = it.first;
                int d = dist[node];
                cout << "Node " << node << " Distance from source is " << d << endl;
            }
        }
/*
//traversing to all the nodes
        void bfs(T src){
            map<T, bool> visited;
            queue<T> q;
            q.push(src);
            visited[src] = true;
            while(!q.empty()){
                T node = q.front();
                q.pop();
                cout << node << " ";
                for(auto it:l[node]){
                    if(!visited[it]){
                        q.push(it);
                        visited[it] = true;
                    }
                }
            }   
        }
*/
};
int main(){
    graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.bfs(0);
    return 0;
}
