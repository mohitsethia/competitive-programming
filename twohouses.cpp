#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
int main(){
    int n, x;
    cin >> n;
    vector<pair<int, int> > k;
    for(int i = 1; i <= n; i++){
        cin >> x;
        k.push_back(make_pair(x, i));
    }
    sort(k.begin(), k.end());
    int i = 0, j = k.size()-1;
    x = k[0].second;
    int y = k[k.size()-1].second;
    while(true){
        cout << "? " << x << " " << y << endl;
        string s;
        cin >> s;
        if(s == "Yes"){
            cout << "! " << x << " " << y << endl;
            cout.flush();
            return 0;
        }
        if(abs(k[i+1].second-k[j].second) > abs(k[i].second-k[j-1].second)){
            i++;
            x = k[i].second;
            y = k[j].second;
        }
        else{
            j--;
            x = k[i].second;
            y = k[j].second;
        }
        if(i == j){
            cout << "! 0 0\n";
            cout.flush();
            return 0;
        }
    }
    return 0;
}
