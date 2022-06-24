#include<iostream>
#include<algorithm>

using namespace std;

const int M = 100;

int memory[M];

int main(){
    int t, m;
    cin >> t >> m;
    int y = 1;
    while(t--){
        string s;
        cin >> s;
        if(s == "alloc"){
            int n;
            cin >> n;
            bool null = true;
            for(int i = 0; i+n-1 < m; i++){
                bool free = true;
                for(int j = i; j < i+n; j++){
                    if(memory[j]){
                        free = false;
                        break;
                    }
                }
                if(free){
                    cout << y << "\n";
                    for(int j = i; j < i+n; j++){
                        memory[j] = y;
                    }
                    y++;
                    null = false;
                    break;
                }
            }
            if(null){
                cout << "NULL\n";
            }
        }
        else if(s == "erase"){
            int x;
            cin >> x;
            bool good = false;
            for(int i = 0; i < m; i++){
                if(memory[i] && memory[i] == x){
                    memory[i] = 0;
                    good = true;
                }
            }
            if(!good){
                cout << "ILLEGAL_ERASE_ARGUMENT\n";
            }
        }
        else{
            int j = 0;
            for(int i = 0; i < m; i++){
                if(memory[i]) swap(memory[i], memory[j++]);
            }
        }
    }
    return 0;
}
