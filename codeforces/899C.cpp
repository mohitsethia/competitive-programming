#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define int long long

void print(vector<int> &a){
    cout << a.size() << " ";
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}

int32_t main(){
    int n;
    cin >> n;
    int total = n*(n+1)/2;
    int needed = total/2;
    if(total%2){
        cout << "1\n";
        if(n == needed){
            cout << "1 " << n << "\n";
        }
        else if(n-1 == needed){
            cout << "1 " << n-1 << "\n";
        }
        else{
            vector<int> a;
            for(int i = n; i >= 1; i--){
                if(needed-i >= 0){
                    needed -= i;
                    a.push_back(i);
                }
                if(needed == 0) break;
            }
            print(a);
        }
    }
    else{
        cout << "0\n";
        if(n == needed){
            cout << "1 " << n << "\n";
        }
        else{
            vector<int> a;
            for(int i = n; i >= 1; i--){
                if(needed-i >= 0){
                    needed -= i;
                    a.push_back(i);
                }
                if(needed == 0) break;
            }
            print(a);
        }
    }
    return 0;
}
