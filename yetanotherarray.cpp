#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int> > a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end(), greater<pair<int, int> >());
    ll sumbeauty = 0;
    vector<int> ind(m*k);
    for(int i = 0; i < m*k; i++){
        sumbeauty += a[i].first;
        ind[i] = a[i].second;
    }
    sort(ind.begin(), ind.end());
    vector<int> div(k-1);
    for(int i = 0; i < k-1; i++){
        div[i] = ind[(i+1)*m-1];
    }
    cout << sumbeauty << endl;
    for(int p : div){
        cout << p+1 << " ";
    }
    return 0;
}
