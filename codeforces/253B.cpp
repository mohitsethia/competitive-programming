#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define endl "\n"
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int cnt = 1;
    for(int i = 0; i < n; i++){
        int low = i, high = n-1, ans = i;
        while(low <= high){
            int mid = (low+high)/2;
            if(a[mid] <= 2*a[i]){
                ans = max(ans, mid);
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        cnt = max(cnt, ans-i+1);
    }
    cout << n-cnt << endl;
    return 0;
}

/*
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int i = 0, j = n-1, cnt = 1;
    for(int i = 0; i < n; i++){
        int j = n-1;
        for(j = n-1; j > i; j--){
            if(a[j] <= 2*a[i]){
                cnt = max(cnt, j-i+1);
                break;
            }
        }
        if(j == n-1) break;
    }
    cout << n-cnt << endl;
    return 0;
}
*/