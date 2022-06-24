#include<iostream>
#include<vector>
using namespace std;
vector<int> solution(int A, int B){
    vector<int> sol;
    for(int i = 1; i < B; i++){
        sol.push_back(i);
    }
    for(int i = A; i >= B; i--){
        sol.push_back(i);
    }
    return sol;
}
int main(){
    int A, B;
    cin >> A >> B;
    vector<int> sol = solution(A, B);
    for(auto it : sol){
        cout << it << " ";
    }
    return 0;
}
