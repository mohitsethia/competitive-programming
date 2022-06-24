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
        void addEdge(T x, T y){
            l[x].push_back(y);
//            l[y].push_back(x);
        }
        void dfs_helper(T src, map<T, bool> &visited, list<T> &ordering){
//            cout << src << " ";
            visited[src] = true;
            for(auto p : l[src]){
                if(!visited[p]){
                    dfs_helper(p, visited, ordering);
                }
            }
            ordering.push_front(src);
            return;
        }
        void dfs(){
            map<T, bool> visited;
            list<T> ordering;
            for(auto p : l){
                T node = p.first;
                visited[node] = false;
            }
//            int cnt = 0;
            for(auto p : l){
                T node = p.first;
                if(!visited[node]){
//                    cout << "Component " << cnt << "-->";
//                    cnt++;
                    dfs_helper(node, visited, ordering);
//                    cout << endl;
                }
            }
            for(auto node:ordering){
                cout << node << endl;
            }
        }
};
int main(){
    graph<string> g;
    g.addEdge("Python", "DataPreprocessing");
    g.addEdge("Python", "PyTorch");
    g.addEdge("Python", "ML");  
    g.addEdge("DataPreprocessing", "ML");
    g.addEdge("PyTorch", "DL");
    g.addEdge("ML", "DL");
    g.addEdge("DL", "FaceRecogn");
    g.addEdge("DataSet", "FaceRecogn");
    g.dfs();
/*
    graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    g.addEdge(0, 4);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(8, 8);
    g.dfs();
*/
    return 0;
}
