#include<iostream>
#include<map>
#include<list>
using namespace std;
class graph{
public:
    map<int, list<int> > mp;
    void addEdge(int x, int y){
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    int comp(int src){
        bool visited[1000001] = {false};
        int count = 0;
        for(auto i : mp[src]){
            for(auto nd : mp[i]){
                for(auto pair: mp[nd]){
                    if(pair >= l
                        if(!visited[pair]){
//                        cout << pair << " nd ";
                            visited[pair] = true;
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
};
int main(){
    int n, x;
    cin >> n >> x;
    graph g;
    for(int i = 0; i < n; i++){
        int u, v;
        cin >> u >> v;
        for(int l = u; l < v; l++){
            g.addEdge(l, v);   
        }
    }
    int ans = g.comp(x);
    cout << ans+1 << endl;
    return 0;
}
