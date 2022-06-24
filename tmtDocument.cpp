#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, flag = 1;
        string s;
        cin >> n >> s;
        if(s[0] == 'M' || s[n-1] == 'M'){
            flag = 0;
        }
        int T = 0, M = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'T'){
                T++;
            }
            else{
                M++;
                if(M > T){
                    flag = 0;
                    break;
                }
            }
        }
        if(T != 2*M){
            flag = 0;
        }
        if(!flag){
            cout << "NO\n";
            continue;
        }
        T = 0, M = 0;
        for(int i = n-1; i >= 0 ; i--){
            if(s[i] == 'T'){
                T++;
            }   
            else{
                M++;
                if(M > T){
                    flag = 0;
                    break;
                }
            }
        }
        if(flag){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}
