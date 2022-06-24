#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int32_t main(){
    int a, b;
    cin >> a >> b;
    int sum = 0;
    int x = 0;
    while(sum < a){
        sum += ++x;
    }
    sum -= a;
    vector<int> p;
    for(int i = 1; i <= x; i++){
        if(i != sum){
            p.push_back(i);
        }
    }
    vector<int> q;
    if(sum <= b){
        if(sum){
            q.push_back(sum);
        }
        while(sum + x + 1 <= b){
            sum += ++x;
            q.push_back(x);
        }
    }
    cout << p.size() << "\n";
    for(int i: p){
        cout << i << " " ;
    }
    cout << "\n" << q.size() << "\n";
    for(int i: q){
        cout << i << " " ;
    }
    return 0;
}
