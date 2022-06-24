//weighted Graph
#include<iostream>
#include<map>
#include<list>
using namespace std;
class graph{
    map<string, list<pair<string, int> > > l;
    public:
        void addEdge(string x, string y, bool bidir, int wt){
            l[x].push_back(make_pair(y, wt));
            if(bidir){
                l[y].push_back(make_pair(x, wt));
            }
        }
        void print(){
            for(auto i:l){
                cout << i.first << "->";
                for(auto j:i.second){
                    cout << j.first << " " << j.second << " ";
                }
                cout << endl;
            }
        }
};
int main(){
    graph g;    
    g.addEdge("A", "B", true, 20);
    g.addEdge("B", "D", true, 40);
    g.addEdge("A", "C", true, 10);
    g.addEdge("C", "D", true, 40);
    g.addEdge("A", "D", false, 50);
    g.print();
    return 0;
}
/*
#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
class graph{
    int V;
    list<int> *l;
public:
    graph(int V){
        this->V = V;
        l = new list<int>[V];
    }
    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void print(){
        for(int i = 0; i < V; i++){
            cout << "Vertex " << i << " -> ";
            for(int j:l[i]){
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};
int main(){
    graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 2);
    g.print();
    return 0;
}
*/
