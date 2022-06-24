#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<string> v;
        for(int i=0;i<n;i++){
            string temp;
            cin>>temp;
            v.push_back(temp);
        }
        int op = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i%2 == j%2){
                    if(v[i][j]!='.') op++;
                }else{
                    if(v[i][j]!='*') op++;
                }
            }
        }
        int op1 = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i%2 == j%2){
                    if(v[i][j]!='*') op1++;
                }else{
                    if(v[i][j]!='.') op1++;
                }
            }
        }
        if(n%2==0 || m%2==0)
            cout<<min(op,op1)<<endl;
        else{
            cout<<op1<<endl;
        }       
    }
    return 0;
}

