#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<int> v;
int check(int *a, int n, char *s){
    int count = 0;
    for(int i = 1; i < n; i++){
        if(a[i] > a[i-1] && s[i] < s[i-1]){
            count++;
        }
        if(a[i] < a[i-1] && s[i] > s[i-1]){
            count++;
        }
    }
    return count;
}
void note(int *a, int n, int i, char *s){
    if(i == n){
        int ans = check(a, n, s);
        v.push_back(ans);
        return;
    }
    for(int j = i; j < n; j++){
        s[j] = 'A';
        note(a, n, i+1, s);
        s[j] = 'B';
        note(a, n, i+1, s);
        s[j] = 'C';
        note(a, n, i+1, s);
        s[j] = 'D';
//        note(a, n, i+1, s);
    }
}

int main(){
    int t, tc = 0;
    cin >> t;
    while(tc <= t){
        tc++;
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        char s[n+1];
        note(a, n, 0, s);
        int mn = INT_MAX;
        for(auto it : v){
            if(it < mn){
                mn = it;
            }
        }
        cout << "Case #" << tc << ": " << mn << endl;
    }
    return 0;
}
