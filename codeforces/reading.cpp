#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
using namespace std;
int main(){
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int n, k;
    cin >> n >> k;
    vector<pair<int, int> > v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first;
        v[i].second = i+1;
    }
    sort(v.begin(), v.end());
    cout << v[n-k].first << endl;
    for(int i = n-k; i < n; i++){
        cout << v[i].second << " ";
    }
    return 0;
}
