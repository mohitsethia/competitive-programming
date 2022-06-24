#include<iostream>
#include<map>
#include<list>
using namespace std;
class graph{
    map<int, list<int> > mp;
    int n;
    char mat[51][51];
    public:
        void init(int t){
            n = t;
        }
        void addEdge(int x, int y){
            mp[x].push_back(y);
        }
        void dfshelper(int src, int dest, bool *visited){
            for(auto it : mp[dest]){
                mat[src][it] = 'Y';
                if(!visited[it]){
                    visited[it] = true;
                    dfshelper(src, it, visited);
                  
                }
            }
        }
        void dfs(){
            for(int i = 0; i < n; i++){
                bool visited[51] = {false};
                dfshelper(i, i, visited);
            }
        }
        void getmatrix(){
            for(int i = 0; i <= n; i++){
                for(int j = 0; j <= n; j++){
                    if(i == j){
                        mat[i][j] = 'Y';
                    }
                    else{
                        mat[i][j] = 'N';
                    }
                }
            }
            dfs();
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    cout << mat[i][j];
                }
                cout << endl;
            }
        }
};
int main(){
    int t;
    cin >> t;
    int tc = 1;
    while(t--){
        graph g;
        int n;
        cin >> n;
        g.init(n);
        string in, out;
        cin >> in >> out;
        for(int i = 0; i < n-1; i++){
            if(out[i] == 'Y' && in[i+1] == 'Y'){
                g.addEdge(i, i+1);
            }
            if(in[i] == 'Y' && out[i+1] == 'Y'){
                g.addEdge(i+1, i);
            }
        }
        cout << "Case #" << tc << ": " << endl;
        tc++;
        g.getmatrix();
    }
    return 0;
}
