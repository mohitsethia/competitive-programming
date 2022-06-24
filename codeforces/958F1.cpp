#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int N = 102;
int n, m;
int a[N];
int want[N];
int have[N];

bool check(){
    for(int i = 1; i <= m; i++){
        if(a[i] != want[i]) return 0;
    }
    return 1;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> have[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> want[i];
    }
    bool ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            memset(a, 0, sizeof(a));
            for(int k = i; k <= j; k++){
                a[have[k]]++;
            }
            ans |= check();
            if(ans) break;
        }
        if(ans) break;
    }
    cout << (ans ? "YES\n" : "NO\n");
    return 0;
}
