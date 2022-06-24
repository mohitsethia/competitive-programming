#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, rank, arr[100000] = {0};
        cin >> n;
        string name;
        memset(arr, 0, sizeof arr);
        for(int i = 0; i < n; i++){
            cin >> name >> rank;    
            arr[rank]++;
        }
        int actual_rank = 1;
        int sum = 0;
        for(int i = 1;i <= n; i++){
            while(arr[i]){
                sum += abs(actual_rank - i);
                arr[i]--;
                actual_rank++;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
