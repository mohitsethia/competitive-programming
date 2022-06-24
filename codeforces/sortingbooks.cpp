#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    int books[n];
    for(int i = 0; i < n; i++){
        cin >> books[i];
    }
    int visited[n] = {0}, need = 0, cnt = 0, f = 0;
    for(int i = n-1; i >= 0; i--){
        if(visited[i]){
            continue;
        }
        visited[i] = 1;
        int j = i-1;
        while(j >= 0){
            if(books[i] != books[j]){
                need = 1;
            }
            if(need && books[i] == books[j]){
                f++;
            }
            j--;
        }
        cnt += f;
        f = 0;
    }
    cout << 
    return 0;
}
