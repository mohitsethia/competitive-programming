//for every i and j where a[i] < a[j] && b[i] < b[j]
//maximum would be b[j];

#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
    int n;
    cin >> n;
    pair<int, int> a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a+n);
    int best = -1;
    for(int i = 0; i < n; i++){
        if(best <= a[i].second) best = a[i].second;
        else best = a[i].first;
    }
    cout << best << endl;
    return 0;
}
